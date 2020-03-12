#ifndef ILOGGER_H
#define ILOGGER_H
#include <string>

namespace LogManager::Interfaces {
    template<typename T>
    class ILogger
    {
        const unsigned int LOG_MESSAGE_BUFFER_SIZE = 1024;
    protected:
        T m_log;
    public:
        virtual ~ILogger() {}
        virtual void LogInfo(const std::string& message) = 0;
        virtual void LogWarning(const std::string& message) = 0;
        virtual void LogError(const std::string& message) = 0;

        template<typename ...Args>
        std::string GetLogMessage(const char* format, Args&... args)
        {
            char log_msg[LOG_MESSAGE_BUFFER_SIZE];
            snprintf(log_msg, LOG_MESSAGE_BUFFER_SIZE, format, args...);
            return log_msg;
        }
    };
}
#endif // ILOGGER_H
