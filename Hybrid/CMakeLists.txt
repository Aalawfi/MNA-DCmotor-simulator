set(HYBRID_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
file(GLOB_RECURSE HYBRID_HEADERS "${HYBRID_INCLUDE_DIR}/*.h")
file(GLOB_RECURSE HYBRID_SOURCE "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_library(Hybrid STATIC ${HYBRID_HEADERS} ${HYBRID_SOURCE})
target_include_directories(Hybrid PUBLIC ${HYBRID_INCLUDE_DIR})
target_link_libraries(Hybrid Mna Signal)