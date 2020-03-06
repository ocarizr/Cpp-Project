cmake_minimum_required(VERSION 3.5)

project(NamedPipe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(library_name ConfigManager)

set(readConfig_headers
    ConfigEnum.h
    EnumParser.h
    ConfigurationParser.h
    IReadConfig.h
    ReadConfig.h
    ReadConfigConcretions.h
    ReadConfigCfg.h)

set(readConfig_sources
    ReadConfigCfg.cpp)

add_library(${library_name} ${readConfig_sources} ${readConfig_headers})
