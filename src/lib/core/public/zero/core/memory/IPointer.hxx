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

#ifndef ZERO_CORE_I_POINTER_HXX
#define ZERO_CORE_I_POINTER_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_API_HPP
#include <zero/core/cfg/zero_api.hpp>
#endif /// !ZERO_API_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// zero::core::IPointer
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/*!
		 \brief Smart-pointer behavior contract

		 \version 1.0
		*/
		template <typename T>
		ZERO_API class IPointer
		{

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			 \throws no exceptions
			*/
			virtual ~IPointer() noexcept = default;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// GETTERS & SETTERS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			 \brief Returns raw-pointer

			 \throws - no exceptions
			*/
			virtual T* get() const noexcept = 0;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			virtual void reset() noexcept = 0;
			virtual void reset(T* const pAddress)  = 0;

			virtual long use_count() const noexcept = 0;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// zero::core::IPointer

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// zero::core

} /// zero

template <typename T>
using zIPointer = zero::core::IPointer<T>;
#define ZERO_CORE_I_POINTER_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CORE_I_POINTER_HXX
