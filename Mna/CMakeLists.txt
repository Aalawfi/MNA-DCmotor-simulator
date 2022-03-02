set(MNA_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
file(GLOB_RECURSE MNA_HEADERS "${MNA_INCLUDE_DIR}/*.h")
file(GLOB_RECURSE MNA_SOURCE "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_library(Mna STATIC ${MNA_HEADERS} ${MNA_SOURCE})
target_include_directories(Mna PUBLIC ${MNA_INCLUDE_DIR})
target_link_libraries(Mna Common Math)