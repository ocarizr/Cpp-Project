#ifndef IREADCONFIG_H
#define IREADCONFIG_H
#include <map>
#include "ConfigEnum.h"

namespace ReadConfig {
    namespace Interfaces {
        template<typename T>
        class IReadConfig
        {
        protected:
            std::string m_file_path;
        public:
            IReadConfig(std::string f) noexcept : m_file_path(f){}
            virtual ~IReadConfig();

            const virtual std::map<Enums::Configurations, T> ReadConfigurations() const = 0;
        };
    }
}
#endif // IREADCONFIG_H
