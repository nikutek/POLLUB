cmake_minimum_required(VERSION 3.20)
project(Wirtualny_ekosystem)

set(CMAKE_CXX_STANDARD 20)

# Include all source files
file(GLOB SOURCES
        "main.cpp"
        "InputReader.cpp"
        "Ecosystem.cpp"
        "Organisms/*.cpp"

)

add_executable(Wirtualny_ekosystem ${SOURCES})
