// All rights reserved.
// License: see LICENSE.txt
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
// in the credits of the application, if such credits exist.
// The authors of this work must be notified via email (code4un@yandex.ru) in
// this case of redistribution.
// 3. Neither the name of copyright holders nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
// IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// HEADER
#ifndef ZERO_CORE_MEMORY_MANAGER_HPP
#include "../../../../public/zero/core/memory/MemoryManager.hpp"
#endif // !ZERO_CORE_MEMORY_MANAGER_HPP

// DEBUG
#if defined(ZERO_DEBUG)

// Include zero::debug
#ifndef ZERO_DEBUG_HPP
#include <zero/core/cfg/zero_debug.hpp>
#endif // !ZERO_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MemoryManager
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// FIELDS
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		MemoryManager::instance_ptr MemoryManager::mInstance(nullptr);

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// CONSTRUCTOR & DESTRUCTOR
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		MemoryManager::MemoryManager()
		{
#if defined(ZERO_DEBUG) /// DEBUG
			zLog::debug("MemoryManager::construct");
#endif /// DEBUG
		}

		MemoryManager::~MemoryManager() ZERO_NOEXCEPT
		{
#if defined(ZERO_DEBUG) /// DEBUG
			zLog::debug("MemoryManager::destruct");
#endif /// DEBUG
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// METHODS
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		void MemoryManager::Initialize( MemoryManager* const pInstance )
		{
#if defined(ZERO_DEBUG) /// DEBUG
			zAssert(!mInstance && "MemoryManager::Initialize: already initialized");

			zLog::debug("MemoryManager::Initialize");
#else /// !DEBUG
			if ( mInstance )
			{
				delete pInstance;
				return;
			}
#endif /// DEBUG

			mInstance = pInstance;
		}

		void MemoryManager::Terminate() ZERO_NOEXCEPT
		{
#if defined(ZERO_DEBUG) /// DEBUG
			zAssert(mInstance && "MemoryManager::Terminate: not initialized");

			zLog::debug("MemoryManager::Terminate");
#else /// !DEBUG
			if (!mInstance)
				return;
#endif /// DEBUG

			delete mInstance;
			mInstance = nullptr;
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	}

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
