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

// Include zero::atomic
#ifndef ZERO_ATOMIC_HPP
#include <zero/core/cfg/zero_atomic.hpp>
#endif /// !ZERO_ATOMIC_HPP

// Include zero::mutex
#ifndef ZERO_MUTEX_HPP
#include <zero/core/cfg/zero_mutex.hpp>
#endif /// !ZERO_MUTEX_HPP

// DEBUG
#if defined(ZERO_DEBUG)

// Include zero::debug
#ifndef ZERO_DEBUG_HPP
#include <zero/core/cfg/zero_debug.hpp>
#endif // !ZERO_DEBUG_HPP

#endif
// DEBUG

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
		ZERO_API class MemoryManager final
		{

		private:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// TYPES
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			using instance_ptr = MemoryManager*;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELDS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			static instance_ptr mInstance;
			zAtomic<size_t> mAllocated;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			\brief MemoryManager constructor
			*/
			explicit MemoryManager()
				: mAllocated(sizeof(MemoryManager))
			{
#if defined(ZERO_DEBUG) /// DEBUG
				zLog::debug("MemoryManager::construct");
#endif /// DEBUG
			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			MemoryManager(const MemoryManager&) = delete;
			MemoryManager(MemoryManager&&)      = delete;

			MemoryManager& operator=(const MemoryManager&) = delete;
			MemoryManager& operator=(MemoryManager&&)      = delete;

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
			~MemoryManager() ZERO_NOEXCEPT
			{
#if defined(ZERO_DEBUG) /// DEBUG
				zLog::debug("MemoryManager::destruct");
#endif /// DEBUG
			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// GETTERS & SETTERS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			  \brief Retursn bytes allocated

			  \thread_safety - atomics used
			  \throws - no exceptions
			*/
			static size_t getAllocated() noexcept
			{
#ifdef ZERO_DEBUG /// DEBUG
				zAssert(mInstance != nullptr && "MemoryManager::getAllocated: instance not set");
#endif /// DEBUG

				const size_t output(mInstance->mAllocated);
				return output;
			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			  \brief Initialize MemoryManager instance

			  \thread_safety - main-thread only
			*/
			static void Initialize()
			{
#if defined(ZERO_DEBUG) /// DEBUG
				zAssert(!mInstance && "MemoryManager::Initialize: already initialized");

				zLog::debug("MemoryManager::Initialize");
#else /// !DEBUG
				if ( mInstance )
					return;
#endif /// DEBUG

				mInstance = new MemoryManager();
			}

			/*!
			  \brief Terminate MemoryManager

			  \thread_safety - main-thread only
			  \throws - no exceptions
			*/
			static void Terminate() ZERO_NOEXCEPT
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

			template <typename T, typename... Args>
			static T* New(Args&&... args)
			{
#ifdef ZERO_DEBUG /// DEBUG
				zAssert(mInstance != nullptr && "MemoryManager::New: instance not set");
#endif /// DEBUG

				mInstance->mAllocated += sizeof(T);

				return new T(args...);
			}

			template <typename T>
			static T* NewArray(const size_t count)
			{
#ifdef ZERO_DEBUG /// DEBUG
				zAssert(mInstance != nullptr && "MemoryManager::NewArray: instance not set");
				zAssert(count && "MemoryManager::NewArray: invalid count");
#endif /// DEBUG

				mInstance->mAllocated += sizeof(T) * count;

				return new T[count]();
			}

			template <typename T>
			static void Delete(T* const ptr) noexcept
			{
#ifdef ZERO_DEBUG /// DEBUG
				zAssert(mInstance != nullptr && "MemoryManager::Delete: instance not set");
#endif /// DEBUG

				if (!ptr)
					return;

				mInstance->mAllocated -= sizeof(T);

				delete ptr;
			}

			template <typename T>
			static void DeleteArray(T* const ptr, const size_t count) noexcept
			{
#ifdef ZERO_DEBUG /// DEBUG
				zAssert(mInstance != nullptr && "MemoryManager::DeleteArray: instance not set");
				zAssert(count && "MemoryManager::DeleteArray: invalid count");
#endif /// DEBUG

				if (!ptr)
					return;

				mInstance->mAllocated -= sizeof(T) * count;

				delete[] ptr;
			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// zero::core::MemoryManager

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// zero::core

} /// zero

using zMemory = zero::core::MemoryManager;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !ZERO_CORE_MEMORY_MANAGER_HPP
