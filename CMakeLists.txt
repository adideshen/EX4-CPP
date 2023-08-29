cmake_minimum_required(VERSION 3.16)
project(ex4_adideshen)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4_adideshen
        Activation.h
        Dense.h
        main.cpp
        Matrix.cpp
        Matrix.h
        MlpNetwork.h
        MlpNetwork.cpp
        Activation.cpp
        Dense.cpp)
