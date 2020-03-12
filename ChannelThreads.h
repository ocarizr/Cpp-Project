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

        for(uint16_t i = 0; i < channel_count;)
        {
            if(StartChannel(logger)) ++i;
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

    [[nodiscard]] bool StartChannel(LogManager::Logger<V>& logger)
    {
        bool ret = true;

        try
        {
            auto channel = Channel(logger, 0); // Channels also needs to receive a struct with its configs
            m_channels.push_back(std::move(channel));

            auto c = m_channels.rbegin();

            auto func = [&c]()
            {
                c->Start();
            };

            m_channel_threads.emplace_back(std::move(func));

        }
        catch(std::exception& e)
        {
            char* what;
            strcpy(what, e.what());
            logger.LogError(logger.GetLogMessage("[%s] - %s", __func__, what));

            ret = false;
        }
        catch(...)
        {
            logger.LogError(logger.GetLogMessage("[%s] - Unknown Error", __func__));

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
