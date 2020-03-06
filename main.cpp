#include <iostream>

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "ConfigManager/ReadConfig.h"
#include "ConfigManager/ReadConfigConcretions.h"

template <typename T>
void populate_configs(ConfigManager::Interfaces::IReadConfig<T>* reader)
{
    using namespace ConfigManager;
    auto configs = reader->ReadConfigurations();

    for(const auto& config : configs)
    {
        switch (config.first) {
        case Enums::Configurations::PIPENAME:
            break;
        case Enums::Configurations::PIPEPATH:
            break;
        case Enums::Configurations::BUFFERSIZE:
            break;
        default:
            break;
        }
    }
}

int main()
{
    auto config_reader = ConfigManager::Read(
                std::move(new ConfigManager::Concretions::ReadConfigCfg("Config")));
    populate_configs(&config_reader);

    return 0;
}
