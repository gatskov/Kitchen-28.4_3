cmake_minimum_required (VERSION 3.24)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable (Kitchen  "main.cpp ""kit.cpp"" ${MY_INCLUDE_DIR}/kit.h")
target_include_directories(Kitchen PUBLIC ${MY_INCLUDE_DIR})
