#include <iostream>

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "ConfigManager/ConfigManagerLib.h"
#include "LogManager/LogManagerLib.h"

int main()
{
    auto logger = LogManager::Logger(
                std::move(new LogManager::Concretions::SpdLogger(
                              spdlog::basic_logger_mt("log", "Log/log.txt"))));

    auto config_storage = ConfigManager::Configurations::AppConfig(
                ConfigManager::Reader(std::move(new ConfigManager::Concretions::ReadConfigCfg("Config")))
                .ReadConfigurations());

    for(auto& config : config_storage.GetConfigurationMap())
    {
        std::cout << config.second << std::endl;
        logger.LogInfo(config.second);
    }

    return 0;
}
