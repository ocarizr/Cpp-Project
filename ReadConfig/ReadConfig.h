#ifndef READCONFIG_H
#define READCONFIG_H
#include "IReadConfig.h"

namespace ReadConfig {
    template<typename T>
    class Read : public Interfaces::IReadConfig<T>
    {
        Interfaces::IReadConfig<T>* m_config_behavior;
    public:
        Read() = delete;
        explicit Read(Interfaces::IReadConfig<T>*&& config) noexcept : m_config_behavior(config) {}

        ~Read()
        {
            delete m_config_behavior;
        }

        const virtual std::map<Enums::Configurations, T> ReadConfigurations() const
        {
            return m_config_behavior->ReadConfigurations();
        }
    };
}
#endif // READCONFIG_H
