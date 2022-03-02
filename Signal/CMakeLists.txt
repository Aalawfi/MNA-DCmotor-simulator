set(SIGNAL_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
file(GLOB_RECURSE SIGNAL_HEADERS "${SIGNAL_INCLUDE_DIR}/*.h")
file(GLOB_RECURSE SIGNAL_SOURCE "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_library(Signal STATIC ${SIGNAL_HEADERS} ${SIGNAL_SOURCE})
target_include_directories(Signal PUBLIC ${SIGNAL_INCLUDE_DIR})
target_link_libraries(Signal Common)