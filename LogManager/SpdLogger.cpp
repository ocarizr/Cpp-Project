#include "SpdLogger.h"

namespace LogManager::Concretions {
    SpdLogger::SpdLogger(std::shared_ptr<spdlog::logger> logger)
    {
        m_log.reset();
        m_log = logger;
    }

    void SpdLogger::LogInfo(const std::string& message)
    {
        m_log.get()->info(message);
    }

    void SpdLogger::LogWarning(const std::string& message)
    {
        m_log.get()->warn(message);
    }

    void SpdLogger::LogError(const std::string& message)
    {
        m_log.get()->error(message);
    }
}
