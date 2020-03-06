cmake_minimum_required(VERSION 3.5)

project(NamedPipe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project_name
    CppProject)
set(project_sources
    main.cpp)

add_executable(${project_name} ${project_sources})

add_subdirectory(ConfigManager/)

set(library_names
    ConfigManager)

target_link_libraries(${project_name} LINK_PUBLIC ${library_names})
