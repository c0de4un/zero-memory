# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
# zero-logger
# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( DEBUG )
	add_subdirectory( ${ZERO_LOGGER_DIR} )
endif ( DEBUG )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
# zero-async
# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

add_subdirectory( ${ZERO_ASYNC_DIR} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
# googletest
# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( ZERO_TEST_ENABLED )
	add_subdirectory( ${GTEST_DIR} )
endif ( ZERO_TEST_ENABLED )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
