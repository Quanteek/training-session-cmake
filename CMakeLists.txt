cmake_minimum_required(VERSION 2.8)

project(helloworld)

find_package(Boost COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRECTORIES})
link_directories(${Boost_LIBRARY_DIRS})

set(SRC
  Model.cpp
  OutputFile.cpp
  )
add_library(mylib ${SRC})

set(EXE_NAME hello)
add_executable(${EXE_NAME} main.cpp)
target_link_libraries(${EXE_NAME} mylib)
target_link_libraries(${EXE_NAME} ${Boost_LIBRARIES})

enable_testing()
set(TEST_EXE_NAME algo_test)
add_executable(${TEST_EXE_NAME} AlgorithmTest.cpp)
add_test(${TEST_EXE_NAME} ${CMAKE_CURRENT_BINARY_DIR}/${TEST_EXE_NAME})
target_link_libraries(${TEST_EXE_NAME} ${Boost_LIBRARIES})
