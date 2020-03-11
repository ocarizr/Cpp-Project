#ifndef CLIENTFEEDERAPPLICATION_H
#define CLIENTFEEDERAPPLICATION_H
#include <thread>

#include "ChannelThreads.h"

class ClientFeederApplication
{
    LogManager::Logger<std::shared_ptr<spdlog::logger>> m_logger;
    ConfigManager::Configurations::AppConfig m_configs;

    std::atomic_bool m_continue;

    // Add others application parameters if necessary

public:
    ClientFeederApplication(ClientFeederApplication&&) = delete;
    ClientFeederApplication(const ClientFeederApplication&) = delete;
    ClientFeederApplication &operator=(ClientFeederApplication&&) = delete;
    ClientFeederApplication &operator=(const ClientFeederApplication&) = delete;

    ClientFeederApplication(LogManager::Logger<std::shared_ptr<spdlog::logger>>& logger,
                            ConfigManager::Configurations::AppConfig& configs) :
        m_logger(logger),
        m_configs(configs),
        m_continue(true)
    {}

    ~ClientFeederApplication() {}

    void Stop()
    {
        m_continue.store(false);
    }

    int Start()
    {
        int ret = 0;
        try
        {
            auto channel_threads = ChannelThreads(m_configs.GetConfigurationMap(), m_logger);

            while (m_continue.load())
            {
                 std::this_thread::sleep_for(std::chrono::seconds(10));
            }
        }
        catch (std::exception& e)
        {
            char log_msg[LOG_MESSAGE_BUFFER_SIZE];
            snprintf(log_msg, LOG_MESSAGE_BUFFER_SIZE, "%s - %s", __func__, e.what());
            m_logger.LogError(log_msg);
            ret = -1;
        }
        catch(...)
        {
            char log_msg[LOG_MESSAGE_BUFFER_SIZE];
            snprintf(log_msg, LOG_MESSAGE_BUFFER_SIZE, "%s - %s", __func__, "Unknown Error");
            m_logger.LogError(log_msg);
            ret = -1;
        }

        return ret;
    }
};

#endif // CLIENTFEEDERAPPLICATION_H
