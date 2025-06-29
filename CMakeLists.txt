cmake_minimum_required(VERSION 3.31)
project(Project2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project2 main.cpp
        main.h
        InvestmentAccount.cpp
        InvestmentAccount.h)
