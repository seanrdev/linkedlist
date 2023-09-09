file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/dll/*.h")

add_library(dll_library dll.c ${HEADER_LIST})
target_include_directories(dll_library PUBLIC ../../include)
target_compile_features(dll_library PUBLIC cxx_std_11)

add_library(node_library node.c ${HEADER_LIST})
target_include_directories(node_library PUBLIC ../../include)
target_compile_features(node_library PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

