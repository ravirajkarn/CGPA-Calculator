cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CGPA_Calculator)

# Adding third party dependencies
include(FetchContent)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.1.1
)
FetchContent_MakeAvailable(fmt)

# project build start
add_library(header CGPA/classs.h)

find_package(fmt)
add_executable(CGPA_Calculator CGPA/main.cpp)
target_link_libraries(CGPA_Calculator PRIVATE fmt::fmt)
target_link_libraries(CGPA_Calculator PRIVATE header)
set_target_properties(header PROPERTIES LINKER_LANGUAGE CXX)
