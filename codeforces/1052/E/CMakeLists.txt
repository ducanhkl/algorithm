cmake_minimum_required(VERSION 3.14)
project(E)

set(CMAKE_CXX_STANDARD 14)

add_executable(E
        bin/Debug/E.exe
        obj/Debug/main.o
        E.cbp
        E.depend
        E.layout
        inp.txt
        main.cpp)
