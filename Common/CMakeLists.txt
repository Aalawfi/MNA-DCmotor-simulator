set(COMMON_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
file(GLOB_RECURSE COMMON_HEADERS "${COMMON_INCLUDE_DIR}/*.h")
file(GLOB_RECURSE COMMON_SOURCE "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_library(Common STATIC ${COMMON_HEADERS} ${COMMON_SOURCE})
target_include_directories(Common PUBLIC ${COMMON_INCLUDE_DIR})