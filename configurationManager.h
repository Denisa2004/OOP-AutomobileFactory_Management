#ifndef CONFIGURATION_MANAGER_H
#define CONFIGURATION_MANAGER_H

#include <string>

class ConfigurationManager
{
private:
    static ConfigurationManager* instance;
    std::string configData;

    ConfigurationManager() : configData("Default Configuration") {}

public:
    static ConfigurationManager* getInstance()
    {
        if (!instance)
        {
            instance = new ConfigurationManager();
        }
        return instance;
    }

    std::string getConfigData() const
    {
        return configData;
    }

    void setConfigData(const std::string& data)
    {
        configData = data;
    }
};

ConfigurationManager* ConfigurationManager::instance = nullptr;

#endif
