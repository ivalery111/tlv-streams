add_executable(test_stream_init test_stream_init.c)
target_link_libraries(test_stream_init net::stream)
add_test(
    NAME test_stream_init
    COMMAND test_stream_init
)

add_executable(test_stream_ser test_stream_ser.c)
target_link_libraries(test_stream_ser net::stream)
add_test(
    NAME test_stream_ser
    COMMAND test_stream_ser
)