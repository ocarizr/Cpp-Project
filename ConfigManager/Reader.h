#ifndef READCONFIG_H
#define READCONFIG_H
#include <sstream>

#include "IReadConfig.h"
#include "../LogManager/LogManagerLib.h"

namespace ConfigManager {
    template<typename T>
    class Reader : public Interfaces::IReadConfig<T>
    {
        using Logger = LogManager::Logger<std::shared_ptr<spdlog::logger>>;
        Interfaces::IReadConfig<T>* m_config_behavior;
        Logger* m_logger;
    public:
        Reader() = delete;
        Reader(Interfaces::IReadConfig<T>*&& config, Logger& logger) noexcept :
            m_config_behavior(config), m_logger(&logger) {}

        ~Reader()
        {
            delete m_config_behavior;
        }

        const std::map<Enums::Configurations, T> ReadConfigurations() override
        {
            auto result = std::map<Enums::Configurations, T>();

            try
            {
                result = m_config_behavior->ReadConfigurations();

                m_logger->LogInfo(
                            m_logger->GetLogMessage(
                                "[%s] - Configuration successfuly readed", __func__));
            }
            catch (std::exception& e)
            {
                char* what;
                strcpy(what, e.what());
                m_logger->LogError(m_logger->GetLogMessage("[%s] - %s", __func__, what));
            }
            catch(...)
            {
                m_logger->LogError(m_logger->GetLogMessage("[%s] - Unknown error", __func__));
            }

            return result;
        }
    };
}
#endif // READCONFIG_H
