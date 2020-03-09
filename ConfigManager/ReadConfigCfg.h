#ifndef READCONFIGCFG_H
#define READCONFIGCFG_H
#include <fstream>
#include <sstream>

#include "IReadConfig.h"
#include "ConfigurationParser.h"
namespace ConfigManager::Concretions {
    class ReadConfigCfg : public Interfaces::IReadConfig<std::string>
    {
    public:
        explicit ReadConfigCfg(std::string file_path)
        {
            m_file_path = file_path;
        }

        const std::map<Enums::Configurations, std::string> ReadConfigurations() const override;
    };
}

#endif // READCONFIGCFG_H
