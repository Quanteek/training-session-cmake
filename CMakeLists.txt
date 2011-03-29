cmake_minimum_required(VERSION 2.8)

project(helloworld)

set(SRC
  main.cpp
  Model.cpp
  OutputFile.cpp
  )

set(EXE_NAME hello)

add_executable(${EXE_NAME} ${SRC})
