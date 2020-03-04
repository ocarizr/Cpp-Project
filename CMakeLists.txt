cmake_minimum_required(VERSION 3.5)

project(NamedPipe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(ReadConfig/)

set(project_name
    NamedPipe)
set(project_sources
    main.cpp)

add_executable(${project_name} ${project_sources})
