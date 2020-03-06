#include <iostream>

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "ReadConfig/ReadConfig.h"
#include "ReadConfig/ReadConfigConcretions.h"

template <typename T>
void populate_configs(ReadConfig::Interfaces::IReadConfig<T>* reader)
{
    using namespace ReadConfig;
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
    auto config_reader = ReadConfig::Read(
                std::move(new ReadConfig::Concretions::ReadConfigCfg("Config")));
    populate_configs(&config_reader);

    return 0;
}
