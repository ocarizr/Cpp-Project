#ifndef ILOGGER_H
#define ILOGGER_H
#include <string>

namespace LogManager::Interfaces {
    template<typename T>
    class ILogger
    {
    protected:
        T m_log;
    public:
        virtual ~ILogger<T>() {}
        virtual void LogInfo(const std::string& message) = 0;
        virtual void LogWarning(const std::string& message) = 0;
        virtual void LogError(const std::string& message) = 0;
    };
}
#endif // ILOGGER_H
