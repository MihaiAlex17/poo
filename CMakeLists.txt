cmake_minimum_required(VERSION 3.27)
project(poo)

set(CMAKE_CXX_STANDARD 98)

add_executable(poo main.cpp
        Angajati.cpp
        Angajati.h
        Aeroport.cpp
        Aeroport.h
        Avioane.cpp
        Avioane.h
        Pilot.cpp
        Pilot.h
        Stewardesa.cpp
        Stewardesa.h)
