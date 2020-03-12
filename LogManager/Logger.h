#ifndef LOGGER_H
#define LOGGER_H
#include <memory>

#include "ILogger.h"

namespace LogManager {
    template <typename T>
    class Logger : public Interfaces::ILogger<T>
    {
        std::shared_ptr<Interfaces::ILogger<T>> m_logger;
    public:
        Logger() = default;
        Logger(Interfaces::ILogger<T>*&& logger) : m_logger(logger) {}
        ~Logger() {}

        void LogInfo(const std::string& message) override
        {
            m_logger->LogInfo(message);
        }

        void LogWarning(const std::string& message) override
        {
            m_logger->LogWarning(message);
        }

        void LogError(const std::string& message) override
        {
            m_logger->LogError(message);
        }
    };
}
#endif // LOGGER_H
