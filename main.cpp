#include "ConfigManager/ConfigManagerLib.h"
#include "LogManager/LogManagerLib.h"

int main()
{
    auto logger = LogManager::Logger(
                std::move(new LogManager::Concretions::SpdLogger(
                              spdlog::basic_logger_mt("log", "Log/log.txt", true))));

    auto config_storage = ConfigManager::Configurations::AppConfig(
                ConfigManager::Reader(std::move(new ConfigManager::Concretions::ReadConfigCfg("Config")),
                                      logger)
                .ReadConfigurations());

    for(auto& config : config_storage.GetConfigurationMap())
    {
        logger.LogInfo(config.second);
    }

    return 0;
}
