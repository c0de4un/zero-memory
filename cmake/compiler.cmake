# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED ZERO_COMPILER_CONFIGURED )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # COMPILER
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    # C++ Version
    if ( NOT DEFINED PROJECT_CXX_VERSION )
        set( PROJECT_CXX_VERSION 14 )
    endif ( NOT DEFINED PROJECT_CXX_VERSION )

    set( CMAKE_CXX_STANDARD ${PROJECT_CXX_VERSION} )
    set( CMAKE_CXX_STANDARD_REQUIRED ON )

    set( CMAKE_INCLUDE_CURRENT_DIR ON )

    set( CMAKE_AUTOUIC ON )
    set( CMAKE_AUTOMOC ON )
    set( CMAKE_AUTORCC ON )

    # Flags
    if ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
        set( CMAKE_CXX_FLAGS "-fexceptions -fcxx-exceptions" ${CMAKE_CXX_FLAGS} )
    endif ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )

    # Enable Position Independent Code
    set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
    set( CMAKE_POSITION_INDEPENDENT_CODE ON )

    # Testing
    if ( NOT DEFINED ZERO_TEST_ENABLED )
        set( ZERO_TEST_ENABLED ON )
        #option( ZERO_TEST_ENABLED "Enable Testing" ON )
    endif ( NOT DEFINED ZERO_TEST_ENABLED )

    if ( ZERO_TEST_ENABLED )
        include(CTest)
        enable_testing()

        message( STATUS "${PROJECT_NAME} - tests are enabled" )
    endif ( ZERO_TEST_ENABLED )

    set( ZERO_COMPILER_CONFIGURED ON )
    message( STATUS "${PROJECT_NAME} - Compilers configured" )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

endif ( NOT DEFINED ZERO_COMPILER_CONFIGURED )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
