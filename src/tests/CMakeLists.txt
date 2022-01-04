# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

cmake_minimum_required( VERSION ${CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero-memory.tests" )

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_MEMORY_TESTS_PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" )
set( ZERO_MEMORY_TESTS_HEADERS
    "" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_MEMORY_TESTS_PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/" )
set( ZERO_MEMORY_TESTS_SOURCES
    "${ZERO_MEMORY_TESTS_PUBLIC}memory_tests.cpp"
    "${ZERO_MEMORY_TESTS_PUBLIC}core_test.cpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add Executable Object
add_executable( zero_memory_tests ${ZERO_MEMORY_TESTS_HEADERS} ${ZERO_MEMORY_TESTS_SOURCES} )

# Configure Executable Object
set_target_properties( zero_memory_tests PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY ${ZERO_OUTPUT_DIR} )

# Link with zero-logger
target_include_directories( zero_memory_tests PUBLIC "${ZERO_LOGGER_INCLUDE_DIR}" )
target_link_libraries( zero_memory_tests zero_logger )

# Link with zero-async
target_include_directories( zero_memory_tests PUBLIC "${ZERO_ASYNC_CORE_INCLUDE_DIR}" )
target_include_directories( zero_memory_tests PUBLIC "${ZERO_ASYNC_PLATFORM_INCLUDE_DIR}" )
target_link_libraries( zero_memory_tests zero_async )

# Link with zero-memory
target_include_directories( zero_memory_tests PUBLIC "${ZERO_MEMORY_LIB_SRC_DIR}/${PLATFORM}/public" )
target_include_directories( zero_memory_tests PUBLIC "${ZERO_MEMORY_LIB_SRC_DIR}/core/public" )
target_link_libraries( zero_memory_tests zero_memory )

# Link with googletest
target_include_directories( zero_memory_tests PUBLIC "${GTEST_INCLUDE_DIR}" )
target_link_libraries( zero_memory_tests gtest_main )

message( STATUS "${PROJECT_NAME} - tests are built" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
