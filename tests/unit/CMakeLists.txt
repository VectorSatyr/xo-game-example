find_package (doctest CONFIG REQUIRED)
add_executable (xo_unit_tests "tests.cpp" "xo_board.cpp")
add_test (NAME unit_tests COMMAND xo_unit_tests)
target_link_libraries (xo_unit_tests PRIVATE doctest::doctest)