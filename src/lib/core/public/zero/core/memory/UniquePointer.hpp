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

#ifndef ZERO_CORE_UNIQUE_POINTER_HPP
#define ZERO_CORE_UNIQUE_POINTER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::core::IPointer
#ifndef ZERO_CORE_I_POINTER_HXX
#include "IPointer.hxx"
#endif /// !ZERO_CORE_I_POINTER_HXX

// Include zero::memory
#ifndef ZERO_MEMORY_HPP
#include <zero/core/cfg/zero_memory.hpp>
#endif /// !ZERO_MEMORY_HPP

// DEBUG
#ifdef ZERO_DEBUG

// Include zero::debug
#ifndef ZERO_DEBUG_HPP
#include <zero/core/cfg/zero_debug.hpp>
#endif /// !ZERO_DEBUG_HPP

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
		// zero::core::UniquePointer
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/*!
		  \brief Unique pointer implementation,
		  compatable with STL API

		  \version 1.0
		*/
		template <typename T>
		ZERO_API class UniquePointer final : public zIPointer<T>
		{

		private:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELD
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			T* mAddress;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR & DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			  \brief UniquePointer constructor

			  \param pAddress - memory address
			*/
			explicit UniquePointer(T* const pAddress)
				: mAddress(pAddress)
			{
			}

			/*!
			  \brief UniquePointer destructor

			  \throws - no exceptions
			*/
			virtual ~UniquePointer() noexcept
			{
				zDelete(mAddress);
			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// IPointer: GETTERS & SETTERS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			\brief Returns raw-pointer

			\throws - no exceptions
			*/
			virtual T* get() const noexcept final
			{ return mAddress; }

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// IPointer: METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			virtual void reset() noexcept final
			{
				zDelete(mAddress);
				mAddress = nullptr;
			}

			virtual void reset(T* const pAddress) final
			{
				zDelete(mAddress);
				mAddress = pAddress;
			}

			virtual long use_count() const noexcept
			{ return 1; }

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// OPERATORS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			void operator=(T* const ptr) noexcept
			{
				reset(ptr);
			}

			void operator=(nullptr_t) noexcept
			{
				reset();
			}

			bool operator==(T* const ptr)
			{ return mAddress == ptr; }

			bool operator==(zIPointer<T>& ptr)
			{ return ptr.get() == mAddress; }

			T& operator*() noexcept
			{
#ifdef ZERO_DEBUG /// DEBUG
				zAssert(mAddress && "UniquePointer::T& =: fatal logic !");
#endif /// DEBUG

				return *mAddress;
			}
//
//			T* operator->() noexcept
//			{ return get(); }
//
//			void operator=(T* const ptr) noexcept
//			{
//#ifdef ZERO_DEBUG /// DEBUG
//				zAssert(ptr && "UniquePointer::=(T*): bad logic");
//#endif /// DEBUG
//
//				reset(ptr);
//			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// zero::core::UniquePointer

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	}

}

template <typename T>
using zUnique = zero::core::UniquePointer<T>;

#define ZERO_CORE_UNIQUE_POINTER_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CORE_UNIQUE_POINTER_HPP
