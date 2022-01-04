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

// Include googletest
#include <gtest/gtest.h>

// Include zero::memory
#ifndef ZERO_MEMORY_HPP
#include <zero/core/cfg/zero_memory.hpp>
#endif /// !ZERO_MEMORY_HPP

// Include zero::core::Log
#ifndef ZERO_CORE_LOG_HPP
#include <zero/core/log/Log.hpp>
#endif /// !ZERO_CORE_LOG_HPP

// Include zero::core::DefaultLogger
#ifndef ZERO_CORE_DEFAULT_LOGGER_HPP
#include <zero/core/log/DefaultLogger.hpp>
#endif /// !ZERO_CORE_DEFAULT_LOGGER_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// UNITS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

TEST(zero_memory, new_operator) {
	zLog::Initialize(new zDefaultLogger());
	zMemory::Initialize();

	const size_t allocated(zMemory::getAllocated());
	int* const val(zNew<int>(7));
	EXPECT_EQ(zMemory::getAllocated() == (allocated + sizeof(int)), true);
	EXPECT_EQ(val != nullptr, true);
	EXPECT_EQ(*val == 7, true);

	zMemory::Terminate();
	zLog::Terminate();
}

TEST(zero_memory, delete_operator) {
	zLog::Initialize(new zDefaultLogger());
	zMemory::Initialize();

	const size_t allocated(zMemory::getAllocated());
	int* const val = zNew<int>(7);
	zDelete(val);
	EXPECT_EQ(zMemory::getAllocated() == allocated, true);

	zMemory::Terminate();
	zLog::Terminate();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
