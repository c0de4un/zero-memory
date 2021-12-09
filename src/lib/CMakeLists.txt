# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

cmake_minimum_required( VERSION ${CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero-memory.core" )

# Project Version
set( PROJECT_VERSION 0.1 )

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Core
include( "core/core.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( ZERO_BUILD_TYPE STREQUAL "STATIC" )
    # Add STATIC Library Object
    add_library( zero_memory STATIC ${ZERO_MEMORY_SOURCES} )
elseif ( ZERO_BUILD_TYPE STREQUAL "SHARED" )
    # Add SHARED Library Object
    add_library( zero_memory SHARED ${ZERO_MEMORY_SOURCES} )

    # Configure SHARED Library Object
    set_target_properties( zero_memory PROPERTIES
        VERSION ${PROJECT_VERSION}
        LIBRARY_OUTPUT_NAME "zero_memory"
        RUNTIME_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}"
        ARCHIVE_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}"
        LIBRARY_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}" )
endif ( ZERO_BUILD_TYPE STREQUAL "STATIC" )

# Link with zero-config
target_include_directories( zero_memory PUBLIC "${ZERO_CONFIG_INCLUDE_DIR}" )

# Link with zero-logger
if ( DEBUG )
    target_include_directories( zero_memory PUBLIC "${ZERO_LOGGER_INCLUDE_DIR}" )
    target_link_libraries( zero_memory zero_logger )
endif ( DEBUG )

# Link with zero-async
#target_include_directories( zero_memory PUBLIC "${ZERO_CONFIG_INCLUDE_DIR}" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
