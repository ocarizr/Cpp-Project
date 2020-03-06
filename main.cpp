#include <iostream>

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "ConfigManager/ConfigManagerLib.h"

int main()
{
    using namespace ConfigManager;
    auto config_storage = Configurations::AppConfig(
                Reader(std::move(new Concretions::ReadConfigCfg("Config")))
                .ReadConfigurations());

    for(auto& config : config_storage.GetConfigurationMap())
    {
        std::cout << config.second << std::endl;
    }

    return 0;
}
