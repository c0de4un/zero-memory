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

#ifndef ZERO_CORE_MEMORY_MANAGER_HPP
#define ZERO_CORE_MEMORY_MANAGER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_API_HPP
#include <zero/core/cfg/zero_api.hpp>
#endif // !ZERO_API_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// MemoryManager
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/*!
		  \brief Memory management facade

		  \version 1.0
		*/
		ZERO_API class MemoryManager
		{

		private:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			MemoryManager(const MemoryManager&) = delete;
			MemoryManager(MemoryManager&&)      = delete;

			MemoryManager& operator=(const MemoryManager&) = delete;
			MemoryManager& operator=(MemoryManager&&)      = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		protected:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// TYPES
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			using instance_ptr = MemoryManager*;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELDS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			static instance_ptr mInstance;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			 \brief MemoryManager constructor
			*/
			explicit MemoryManager();

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			  \brief MemoryManager destructor

			  \throws no exceptions
			*/
			virtual ~MemoryManager() ZERO_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			  \brief Initialize MemoryManager instance

			  \thread_safety - main-thread only
			  \param pInstance - MemoryManager instance
			*/
			static void Initialize(MemoryManager* const pInstance);

			/*!
			  \brief Terminate MemoryManager

			  \thread_safety - main-thread only
			  \throws - no exceptions
			*/
			static void Terminate() ZERO_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// zero::core::MemoryManager

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// zero::core

} /// zero

using zMemory = zero::core::MemoryManager;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !ZERO_CORE_MEMORY_MANAGER_HPP