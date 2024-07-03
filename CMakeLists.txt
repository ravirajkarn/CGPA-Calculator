cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CGPA_Calculator)

add_library(header CGPA/classs.h)

find_package(fmt)
add_executable(CGPA_Calculator CGPA/main.cpp)
target_link_libraries(CGPA_Calculator PRIVATE fmt::fmt)
target_link_libraries(CGPA_Calculator PRIVATE header)
set_target_properties(header PROPERTIES LINKER_LANGUAGE CXX)