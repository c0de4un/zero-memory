# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_MEMORY_PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/core/public/zero/core/" )
set( ZERO_MEMORY_HEADERS
	"${ZERO_MEMORY_PUBLIC}memory/DefaultMemory.hpp"
	"${ZERO_MEMORY_PUBLIC}memory/MemoryManager.hpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_MEMORY_PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/core/private/zero/core/" )
set( ZERO_MEMORY_SOURCES
	"${ZERO_MEMORY_PRIVATE}memory/DefaultMemory.cpp"
	"${ZERO_MEMORY_PRIVATE}memory/MemoryManager.cpp" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
