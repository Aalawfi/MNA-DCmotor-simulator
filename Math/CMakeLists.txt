set(MATH_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#file(GLOB_RECURSE MATH_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
#file(GLOB_RECURSE MATH_HEADERS ${MATH_INCLUDE}/*.h)

add_library(Math INTERFACE)
target_include_directories(Math INTERFACE ${MATH_INCLUDE})
target_link_libraries(Math INTERFACE Common)