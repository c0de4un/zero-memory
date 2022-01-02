# zero-memory
Memory management Library. Part of zeroEngine.

# Features
 * compile-time type awareness;
 * RTTI;
 * lightweight and designed for mobile;
 * modules-based API;
 * STL pointers & allocators APIs support;
 * shared-memory space (creating new pointer for the same address - counter increases);
 * memory-statistics;
 * shared locks API support (read without locking);
 * spin-locks support for write-operations;

# Tests
 * Run tests by executing them from "bin" directory;

# Requirements
 * C++ 14+;
 * CMake;

# Usage
```C++
#include <zero/core/cfg/zero_mutex.hpp>

int main()
{
	zMutex mutex;
	mutex.lock();
}
```