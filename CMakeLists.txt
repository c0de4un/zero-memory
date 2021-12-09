# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( NOT DEFINED CMAKE_VERSION )
    set( CMAKE_VERSION 3.16 )
endif ( NOT DEFINED CMAKE_VERSION )

cmake_minimum_required( VERSION ${CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero-memory" )

# Project Version
set( PROJECT_VERSION 0.1 )

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# Include Compiler Configs
include( "cmake/compiler.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Options
include( "cmake/options.cmake" )

# Platform
include( "cmake/platform.cmake" )

# BuildType
include( "cmake/buildType.cmake" )

# zeroEngine.API
if ( NOT DEFINED ZERO_CONFIG_INCLUDE_DIR )
    set( ZERO_CONFIG_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/zero-config/public" )

    message( STATUS "${PROJECT_NAME} - including zero-config" )
endif ( NOT DEFINED ZERO_CONFIG_INCLUDE_DIR )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# LIBRARIES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "cmake/libs.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Library
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/src/lib" )

# Tests

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
