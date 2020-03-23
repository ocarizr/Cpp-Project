#ifndef ICHANNEL_H
#define ICHANNEL_H

#include "ConfigManager/ConfigManagerLib.h"
#include "LogManager/LogManagerLib.h"

template<typename T>
class IChannel
{
protected:
    LogManager::Logger<T> m_logger;
    // Add Pipe Information

    uint16_t m_ID;
public:
    IChannel() = delete;
    IChannel(LogManager::Logger<T>& logger, uint16_t id) : m_logger(logger), m_ID(id) {}

    IChannel(const IChannel&) = default;
    IChannel(IChannel&&) = default;

    IChannel& operator=(const IChannel&) = default;
    IChannel& operator=(IChannel&&) = default;

    virtual ~IChannel(){}
    virtual void Start() = 0;
    virtual bool ReadData() = 0;
    virtual bool GetState() = 0;
    LogManager::Logger<T>& GetLogger() { return m_logger; }
};
#endif // ICHANNEL_H
