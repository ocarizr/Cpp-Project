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

set(config_directory
    ${CMAKE_CURRENT_BINARY_DIR}/Congig)

file(MAKE_DIRECTORY ${config_directory})

configure_file(${CMAKE_SOURCE_DIR}/config.cfg
               ${CMAKE_BINARY_DIR}/Config/config.cfg
               COPYONLY)
