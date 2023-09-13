FetchContent_Declare(
  check
  GIT_REPOSITORY https://github.com/libcheck/check.git
  #GIT_TAG        origin/fix-for-cmake-fetchcontent
  GIT_TAG 0.15.2
)
FetchContent_MakeAvailable(check)

add_executable(check_sll check_sll.c)
target_compile_features(check_sll PRIVATE cxx_std_17)
target_link_libraries(check_sll PRIVATE sll_library sllnode_library Check::check)
add_test(NAME check_slltest COMMAND check_sll --output-on-failure) # Command can be a target

add_executable(check_sllnode check_node.c)
target_compile_features(check_sllnode PRIVATE cxx_std_17)
target_link_libraries(check_sllnode PRIVATE sllnode_library Check::check)
add_test(NAME check_sllnodetest COMMAND check_sllnode --output-on-failure) # Command can be a target

