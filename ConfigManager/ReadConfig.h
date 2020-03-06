#ifndef READCONFIG_H
#define READCONFIG_H
#include "IReadConfig.h"

namespace ConfigManager {
    template<typename T>
    class Read : public Interfaces::IReadConfig<T>
    {
        Interfaces::IReadConfig<T>* m_config_behavior;
    public:
        Read() = delete;
        Read(Interfaces::IReadConfig<T>*&& config) noexcept :
            m_config_behavior(config) {}

        ~Read<T>()
        {
            delete m_config_behavior;
        }

        const std::map<Enums::Configurations, T> ReadConfigurations() const override
        {
            return m_config_behavior->ReadConfigurations();
        }
    };
}
#endif // READCONFIG_H
