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

add_executable(test_ser_string test_ser_string.c)
target_link_libraries(test_ser_string net::stream)
add_test(
    NAME test_ser_string
    COMMAND test_ser_string
)

add_executable(test_is_empty test_is_empty.c)
target_link_libraries(test_is_empty net::stream)
add_test(
    NAME test_is_empty
    COMMAND test_is_empty
)

add_executable(test_offset_copy test_offset_copy.c)
target_link_libraries(test_offset_copy net::stream)
add_test(
    NAME test_offset_copy
    COMMAND test_offset_copy
)
