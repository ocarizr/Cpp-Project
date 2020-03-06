#ifndef READCONFIGCFG_H
#define READCONFIGCFG_H
#include <fstream>
#include <sstream>

#include "IReadConfig.h"
#include "ConfigurationParser.h"
namespace ReadConfig {
    namespace Concretions {
        class ReadConfigCfg : public Interfaces::IReadConfig<u_int16_t>
        {
        public:
            explicit ReadConfigCfg(std::string file_path)
            {
                m_file_path = file_path;
            }

            const std::map<Enums::Configurations, u_int16_t> ReadConfigurations() const override;
        };
    }
}

#endif // READCONFIGCFG_H
