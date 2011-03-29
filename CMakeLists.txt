cmake_minimum_required(VERSION 2.8)

project(helloworld)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRECTORIES})

set(SRC
  Model.cpp
  OutputFile.cpp
  )
add_library(mylib ${SRC})

set(EXE_NAME hello)
add_executable(${EXE_NAME} main.cpp)
target_link_libraries(${EXE_NAME} mylib)
target_link_libraries(${EXE_NAME} ${Boost_LIBRARIES})