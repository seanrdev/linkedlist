file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/sll/*.h")

add_library(sll_library sll.c ${HEADER_LIST})
target_include_directories(sll_library PUBLIC ../../include)
target_compile_features(sll_library PUBLIC cxx_std_11)

add_library(sllnode_library node.c ${HEADER_LIST})
target_include_directories(sllnode_library PUBLIC ../../include)
target_compile_features(sllnode_library PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

