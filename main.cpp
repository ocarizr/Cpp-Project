#include "ClientFeederApplication.h"

int main()
{
    auto logger = LogManager::Logger(
                std::move(new LogManager::Concretions::SpdLogger(
                              spdlog::basic_logger_mt("log", "Log/log.txt", true))));

    auto config_storage = ConfigManager::Configurations::AppConfig(
                ConfigManager::Reader(std::move(new ConfigManager::Concretions::ReadConfigCfg("Config")),
                                      logger)
                .ReadConfigurations());

    auto application = ClientFeederApplication(logger, config_storage);

    return application.Start();
}
