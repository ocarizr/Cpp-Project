#ifndef READCONFIG_H
#define READCONFIG_H
#include "IReadConfig.h"

namespace ConfigManager {
    template<typename T>
    class Reader : public Interfaces::IReadConfig<T>
    {
        Interfaces::IReadConfig<T>* m_config_behavior;
    public:
        Reader() = delete;
        Reader(Interfaces::IReadConfig<T>*&& config) noexcept :
            m_config_behavior(config) {}

        ~Reader<T>()
        {
            delete m_config_behavior;
        }

        const std::map<Enums::Configurations, T> ReadConfigurations() override
        {
            return m_config_behavior->ReadConfigurations();
        }
    };
}
#endif // READCONFIG_H
