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

                char log_msg[LOG_MESSAGE_BUFFER_SIZE];
                snprintf(log_msg, LOG_MESSAGE_BUFFER_SIZE, "%s - %s", __func__, "Configuration successfuly readed");
                m_logger->LogInfo(log_msg);
            }
            catch (std::exception& e)
            {
                char log_msg[LOG_MESSAGE_BUFFER_SIZE];
                snprintf(log_msg, LOG_MESSAGE_BUFFER_SIZE, "%s - %s", __func__, e.what());
                m_logger->LogError(log_msg);
            }
            catch(...)
            {
                char log_msg[LOG_MESSAGE_BUFFER_SIZE];
                snprintf(log_msg, LOG_MESSAGE_BUFFER_SIZE, "%s - %s", __func__, "Unknown error");
                m_logger->LogError(log_msg);
            }

            return result;
        }
    };
}
#endif // READCONFIG_H
