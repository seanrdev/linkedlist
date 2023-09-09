add_executable(llist main.c)
target_compile_features(llist PRIVATE cxx_std_17)
target_link_libraries(llist PRIVATE dll_library)

