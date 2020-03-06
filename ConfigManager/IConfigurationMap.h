#ifndef ICONFIGURATIONMAP_H
#define ICONFIGURATIONMAP_H
#include <map>

namespace ConfigManager::Configurations
{
    template<typename T, typename U>
    class IConfigurationMap
    {
    protected:
        std::map<T, U> m_configs;
    public:
        virtual ~IConfigurationMap() {}
        virtual std::map<T, U> GetConfigurationMap() const noexcept = 0;
        virtual void SetConfigurationMap(std::map<T,U> configs) noexcept = 0;
        virtual U GetConfiguration(T key) const noexcept = 0;
        virtual bool HasConfiguration(T key) const noexcept = 0;
    };
}
#endif // ICONFIGURATIONMAP_H
