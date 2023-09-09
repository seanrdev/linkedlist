FetchContent_Declare(
  check
  GIT_REPOSITORY https://github.com/libcheck/check.git
  #GIT_TAG        origin/fix-for-cmake-fetchcontent
  GIT_TAG 0.15.2
)
FetchContent_MakeAvailable(check)

add_executable(check_dll check_dll.c)
target_compile_features(check_dll PRIVATE cxx_std_17)
target_link_libraries(check_dll PRIVATE dll_library node_library Check::check)
add_test(NAME check_dlltest COMMAND check_dll --output-on-failure) # Command can be a target

add_executable(check_node check_node.c)
target_compile_features(check_node PRIVATE cxx_std_17)
target_link_libraries(check_node PRIVATE node_library Check::check)
add_test(NAME check_nodetest COMMAND check_node --output-on-failure) # Command can be a target

