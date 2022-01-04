# zero-memory
Memory management Library. Part of zeroEngine.

# Features
 * compile-time type awareness;
 * RTTI;
 * SHARED and STATIC output support;
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

# Examples
## New & Delete
```C++
#include <zero/core/cfg/zero_memory.hpp>

#include <string>
#include <iostream>

int main()
{
	zMemory::Initialize();

	int* const val(zNew(7));

	size_t allocated(zMemory::getAllocated());
	std::cout << "allocated: " << std::to_string(allocated) << "\n";

	zDelete(val);

	allocated = zMemory::getAllocated();
	std::cout << "allocated: " << std::to_string(allocated) << "\n";

	int* arr(zNewArray(5));
	zDeleteArray(arr, 5);

	zMemory::Terminate();

	return 0;
}
```

## Pointers
```C++
#include <zero/core/cfg/zero_memory.hpp>

int main()
{
	zMemory::Initialize();

	zShared<int> sptr(zNew(9));
	zShared.reset();

	zMemory::Terminate();

	return 0;
}
```
