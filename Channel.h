#ifndef CHANNEL_H
#define CHANNEL_H
#include "IChannel.h"
#include "ConfigManager/ConfigManagerLib.h"

class Channel : public IChannel<std::shared_ptr<spdlog::logger>>
{
public:
    Channel(LogManager::Logger<std::shared_ptr<spdlog::logger>>& logger, uint16_t id) : IChannel(logger, id) {}

    int Start() override { return 0; }
    bool ReadData() override { return true; }
    bool GetState() override { return true; }
};
#endif // CHANNEL_H
