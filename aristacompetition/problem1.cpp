#include <iostream>

std::string repairConfig(std::string originalConfig) {
    size_t pos = originalConfig.find("Ethernet");
    size_t newlinepos = originalConfig.find("\n", pos+1);;
    while(pos != std::string::npos && newlinepos != std::string::npos)
    {
        // Find next new line after "Ethernet"
        if(isdigit(originalConfig[newlinepos-1]))
        {
            if(isdigit(originalConfig[newlinepos-2]))
            {
                continue;
            }
            else {
                // Missing number
                originalConfig.insert(newlinepos-1, "1");
            }
        }
        
        pos = originalConfig.find("Ethernet", newlinepos+1);
        newlinepos = originalConfig.find("\n", pos+1);
    }
    return originalConfig;
}

int main()
{
    std::cout << repairConfig("DeviceAlpha\nEthernet1\nDeviceBis\nEthernet12");
    return 0;
}