cmake_minimum_required(VERSION 3.14)
project(pcsc_project)

set(CMAKE_CXX_STANDARD 14)


add_library(pcsclib
        src/Function.cpp
        src/CosFunction.cpp
        src/SinFunction.cpp
        src/ExpFunction.cpp
        src/LogFunction.cpp
        src/NonLinearEquation.cpp
        src/BisectionMethod.cpp
        src/IterativeMethod.cpp
        src/FixedPoint.cpp
        src/NewtonMethod.cpp
        src/ChordsMethod.cpp
        src/NonLinearSystem.cpp
        src/Function2D.cpp
)

add_subdirectory(googletest)
include_directories(googletest/include)
include_directories(./src)


add_executable(pcsc_main main.cpp)
target_link_libraries(pcsc_main pcsclib)

add_executable(Test_Bisection test/Bisection_test.cpp)
target_link_libraries(Test_Bisection gtest gtest_main pcsclib)

add_executable(Test_Newton test/Newton_test.cpp)
target_link_libraries(Test_Newton gtest gtest_main pcsclib)

add_executable(Test_Chords test/Chords_test.cpp)
target_link_libraries(Test_Chords gtest gtest_main pcsclib)

add_executable(Test_FixedPoint test/FixedPoint_test.cpp)
target_link_libraries(Test_FixedPoint gtest gtest_main pcsclib)

add_executable(Test_Function test/Function_test.cpp)
target_link_libraries(Test_Function gtest gtest_main pcsclib)

