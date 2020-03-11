#ifndef CHANNELTHREADS_H
#define CHANNELTHREADS_H
#include <vector>
#include <thread>

#include "Channel.h"

template<typename T, typename U, typename V>
class ChannelThreads
{
    std::vector<std::thread> m_channel_threads;
    std::vector<Channel> m_channels;

public:
    ChannelThreads(const std::map<T, U>& configs, LogManager::Logger<V>& logger)
    {
        int channel_count = std::count_if(configs.begin(), configs.end(), [](auto& config) { return config.second.find("Channel"); });

        for(uint16_t i = 0; i < channel_count; ++i)
        {
            StartChannel(logger);
        }
    }

    void VerifyChannelHeatlh()
    {
        uint16_t i = 0;
        for(auto channel = m_channels.begin(); channel != m_channels.end(); ++channel)
        {
            if(!channel->GetState())
            {
                auto temp = m_channels[i];
                m_channel_threads[i].join();
                m_channels.erase(channel);

                StartChannel(temp.GetLogger());
            }

            ++i;
        }
    }

    bool StartChannel(LogManager::Logger<V>& logger)
    {
        bool ret = true;

        try
        {
        auto channel = Channel(logger, 0); // Channels also needs to receive a struct with its configs
        m_channels.push_back(channel);

        std::thread thread([&channel](){ channel.Start(); });
        m_channel_threads.push_back(std::move(thread));
        }
        catch(std::exception& e)
        {
            char log_msg[LOG_MESSAGE_BUFFER_SIZE];
            snprintf(log_msg, LOG_MESSAGE_BUFFER_SIZE, "%s - %s", __func__, e.what());
            logger.LogError(log_msg);

            ret = false;
        }
        catch(...)
        {
            char log_msg[LOG_MESSAGE_BUFFER_SIZE];
            snprintf(log_msg, LOG_MESSAGE_BUFFER_SIZE, "%s - %s", __func__, "Unknown Error");
            logger.LogError(log_msg);

            ret = false;
        }

        return ret;
    }

    ~ChannelThreads()
    {
        for(auto& thread : m_channel_threads)
        {
            thread.join();
        }
    }
};
#endif // CHANNELTHREADS_H
