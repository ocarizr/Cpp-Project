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
            virtual ~IReadConfig<T>() {}
            const virtual std::map<Enums::Configurations, T> ReadConfigurations() const = 0;
        };
    }
}
#endif // IREADCONFIG_H
