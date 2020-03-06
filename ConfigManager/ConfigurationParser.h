#ifndef CONFIGURATIONPARSER_H
#define CONFIGURATIONPARSER_H
#include "ConfigEnum.h"
#include "EnumParser.h"

namespace ConfigManager::Enums::Parsers {
    class ConfigurationParser : public EnumParser<Configurations>
    {
    public:
        ConfigurationParser()
        {
            enumMap.emplace("PIPEPATH", PIPEPATH);
            enumMap.emplace("PIPENAME", PIPENAME);
            enumMap.emplace("BUFFERSIZE", BUFFERSIZE);
        }

        ~ConfigurationParser() override {}
    };
}
#endif // CONFIGURATIONPARSER_H
