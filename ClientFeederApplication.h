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
        m_logger.LogInfo(m_logger.GetLogMessage("[%s] - Starting Close Application Process", __func__));
        m_continue.store(false);
    }

    int Start()
    {
        int ret = 0;
        try
        {
            auto channel_threads = ChannelThreads(m_configs.GetConfigurationMap(), m_logger);

            int i = 0;
            while (m_continue.load())
            {
                 std::this_thread::sleep_for(std::chrono::seconds(10));

                 ++i;
                 if(i == 10) Stop(); // remove this after valgrind test
            }

            m_logger.LogInfo(m_logger.GetLogMessage("[%s] - Closing Application", __func__));
        }
        catch (std::exception& e)
        {
            char* what;
            strcpy(what, e.what());
            m_logger.LogError(m_logger.GetLogMessage("[%s] - %s", __func__, what));
            ret = -1;
        }
        catch(...)
        {
            m_logger.LogError(m_logger.GetLogMessage("[%s] - Unknown Error", __func__));
            ret = -1;
        }

        return ret;
    }
};

#endif // CLIENTFEEDERAPPLICATION_H
