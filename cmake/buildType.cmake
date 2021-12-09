# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED ZERO_BUILD_TYPE_DETECTED )

    if ( NOT DEFINED DEBUG )

        if ( ${CMAKE_BUILD_TYPE} STREQUAL Debug )
            message( STATUS "${PROJECT_NAME} - DEBUG-Mode enabled" )

            set( BUILD_TYPE "debug" )
            set( DEBUG ON )
        else ( ${CMAKE_BUILD_TYPE} STREQUAL Debug )
            message( STATUS "${PROJECT_NAME} - DEBUG-Mode disabled" )

            set( BUILD_TYPE "release" )
            set( DEBUG OFF )
        endif ( ${CMAKE_BUILD_TYPE} STREQUAL Debug )

    endif ( NOT DEFINED DEBUG )

    if ( DEBUG )
        set( ZERO_DEBUG ON )
        add_definitions( -DZERO_DEBUG=1 )
    else ( DEBUG )
        set( ZERO_DEBUG OFF )
    endif ( DEBUG )

    if ( NOT DEFINED ZERO_BUILD_TYPE )
        message( STATUS "${PROJECT_NAME} - <ZERO_BUILD_TYPE> not defined, setting to STATIC by default" )

        set( ZERO_BUILD_TYPE "STATIC" )
    endif ( NOT DEFINED ZERO_BUILD_TYPE )

endif ( NOT DEFINED ZERO_BUILD_TYPE_DETECTED )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
