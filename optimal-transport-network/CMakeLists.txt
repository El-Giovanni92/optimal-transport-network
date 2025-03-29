cmake_minimum_required(VERSION 3.28)
project(progetto)

set(CMAKE_CXX_STANDARD 26)

add_executable(progetto main.cpp
        Node.cpp
        Node.h
        QuickUnionUF.cpp
        QuickUnionUF.h
        Progetto.cpp
        Progetto.h
        Edge.cpp
        Edge.h)
