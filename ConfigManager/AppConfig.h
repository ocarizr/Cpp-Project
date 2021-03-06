#ifndef APPCONFIG_H
#define APPCONFIG_H
#include <iostream>
#include <functional>

#include "ConfigEnum.h"
#include "IConfigurationMap.h"
#include "IReadConfig.h"

namespace ConfigManager::Configurations
{
    class AppConfig : public IConfigurationMap<Enums::Configurations, std::string>
    {
        void SetConfigurationMap(std::map<Enums::Configurations, std::string> configs) noexcept override
        {
            m_configs = std::map(configs);
        }

    public:
        AppConfig() { m_configs = std::map<Enums::Configurations, std::string>(); }

        explicit AppConfig(const std::map<Enums::Configurations, std::string> data)
        {
            SetConfigurationMap(data);
        }

        std::map<Enums::Configurations, std::string> GetConfigurationMap() const noexcept override
        {
            return m_configs;
        }

        bool HasConfiguration(Enums::Configurations key) const noexcept override
        {
            return m_configs.find(key) != m_configs.end();
        }

        std::string GetConfiguration(Enums::Configurations key) const noexcept override
        {
            auto it_value = m_configs.find(key);
            return it_value != m_configs.end() ? it_value->second : 0;
        }
    };
}
#endif // APPCONFIG_H
