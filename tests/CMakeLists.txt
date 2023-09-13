list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
set (CTEST_OUTPUT_ON_FAILURE 1)

add_subdirectory(dll)
add_subdirectory(sll)

