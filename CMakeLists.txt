cmake_minimum_required(VERSION 3.5)

project(CppProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wall)
    add_compile_options(-Wextra)
    add_compile_options(-O3)
endif()

set(project_name
    CppProject)
set(project_sources
    main.cpp)
set(project_headers
    ClientFeederApplication.h
    ChannelThreads.h
    IChannel.h
    Channel.h)

add_executable(${project_name} ${project_sources} ${project_headers})

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(${project_name} PRIVATE DEBUG_END_PROGRAM)
endif()

add_subdirectory(ConfigManager/)
add_subdirectory(LogManager/)

target_link_libraries(${project_name} LINK_PUBLIC ConfigManager)
target_link_libraries(${project_name} LINK_PUBLIC LogManager)

set(config_directory
    ${CMAKE_CURRENT_BINARY_DIR}/Config)

file(MAKE_DIRECTORY ${config_directory})

configure_file(${CMAKE_SOURCE_DIR}/config.cfg
               ${CMAKE_BINARY_DIR}/Config/config.cfg
               COPYONLY)
