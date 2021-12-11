# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED ZERO_OUTPUT_DIR )
    set( ZERO_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin/${PLATFROM}" )

    set( STATUS "${PROJECT_NAME} - output path is '${ZERO_OUTPUT_DIR}'" )
endif ( NOT DEFINED ZERO_OUTPUT_DIR )

if ( NOT DEFINED ZERO_CONFIG_INCLUDE_DIR )
    set( ZERO_CONFIG_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/zero-config/public" )
    set( ZERO_CONFIGS_INCLUDED ON )
    message( STATUS "${PROJECT_NAME} - zero-config included" )
endif ( NOT DEFINED ZERO_CONFIG_INCLUDE_DIR )

if ( NOT DEFINED ZERO_LOGGER_INCLUDE_DIR )
    set( ZERO_LOGGER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/zero-logger/src/lib/public" )
    set( ZERO_LOGGER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/zero-logger" )
    message( STATUS "${PROJECT_NAME} - zero-logger included" )
endif ( NOT DEFINED ZERO_LOGGER_INCLUDE_DIR )

if ( NOT DEFINED ZERO_ASYNC_INCLUDE_DIR )
    set( ZERO_ASYNC_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/zero-async/src/lib/public" )
    set( ZERO_ASYNC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/zero-async" )
    message( STATUS "${PROJECT_NAME} - zero-async included" )
endif ( NOT DEFINED ZERO_ASYNC_INCLUDE_DIR )

if ( NOT DEFINED GTEST_INCLUDE_DIR )
    set( GTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/googletest/googletest/include" )
    set( GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/googletest" )
    set( BUILD_GMOCK OFF )
    message( STATUS "${PROJECT_NAME} - googletest included" )
endif ( NOT DEFINED GTEST_INCLUDE_DIR )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
