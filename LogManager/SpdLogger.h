#ifndef SPDLOGGER_H
#define SPDLOGGER_H
#include "ILogger.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace LogManager::Concretions {
    class SpdLogger : public Interfaces::ILogger<std::shared_ptr<spdlog::logger>>
    {
    public:
        SpdLogger(std::shared_ptr<spdlog::logger> logger);

        void LogInfo(const std::string& message) override;
        void LogWarning(const std::string& message) override;
        void LogError(const std::string& message) override;
    };
}
#endif // SPDLOGGER_H
