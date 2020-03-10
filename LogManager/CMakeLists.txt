cmake_minimum_required(VERSION 3.5)

project(NamedPipe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(spdlog/)

set(library_name LogManager)

set(logManager_headers
    Logger.h
    ILogger.h
    SpdLogger.h
    LogManagerLib.h)

set(logManager_sources
    SpdLogger.cpp)

add_library(${library_name} ${logManager_sources} ${logManager_headers})

target_link_libraries(${library_name} spdlog::spdlog_header_only)
