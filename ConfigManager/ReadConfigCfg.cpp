#include "ReadConfigCfg.h"

namespace ConfigManager::Concretions {
    using configMap = std::map<Enums::Configurations, std::string>;
    using ConfigurationParser = Enums::Parsers::ConfigurationParser;

    const configMap ReadConfigCfg::ReadConfigurations()
    {
        configMap result = configMap();

        std::ifstream file;
        std::string file_path = m_file_path + "/config.cfg";

        file.open(file_path);
        std::string data = std::string();

        if(!file.is_open()) throw;

        Enums::Configurations config_item;
        std::string config_data;

        ConfigurationParser parser = ConfigurationParser();

        while(getline(file, data))
        {
            std::stringstream ss(data);
            std::string token = std::string();
            int config = 0;
            while(getline(ss, token, '='))
            {
                if(config == 0)
                {
                    config_item = parser.ParseSomeEnum(token);
                }
                else if (config == 1)
                {
                    config_data = token;
                }
                ++config;
            }

            result.emplace(config_item, config_data);
            config = 0;
        }

        return result;
    }
}
