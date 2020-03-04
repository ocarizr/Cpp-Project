#ifndef ENUMPARSER_H
#define ENUMPARSER_H
#include <map>
#include <iostream>

namespace ReadConfig {
    namespace Enums {
        namespace Parsers {
            template <typename T>
            class EnumParser
            {
            protected:
                std::map <std::string, T> enumMap;
            public:
                EnumParser() {}
                virtual ~EnumParser(){};

                [[nodiscard]] T ParseSomeEnum(const std::string &value) noexcept
                {
                    auto iValue = enumMap.find(value);
                    return iValue->second;
                }
            };
        }
    }
}
#endif // ENUMPARSER_H
