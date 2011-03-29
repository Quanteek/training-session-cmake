cmake_minimum_required(VERSION 2.8)

project(helloworld)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRECTORIES})

set(SRC
  main.cpp
  Model.cpp
  OutputFile.cpp
  )

set(EXE_NAME hello)

add_executable(${EXE_NAME} ${SRC})
target_link_libraries(${EXE_NAME} ${Boost_LIBRARIES})