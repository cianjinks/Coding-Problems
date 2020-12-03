#include <iostream>
#include <vector>
#include <algorithm>

int powerOffAllButOne(int deviceCount, int step) {
    std::vector<int> devices(deviceCount, 1);
    int devicePointer = 0;
    while(std::count(devices.begin(), devices.end(), 1) != 1)
    {
        int stepCopy = step-1;
        while(stepCopy > 0)
        {
            if(devices[devicePointer] == 1)
            {
                stepCopy--;
            }
            devicePointer++;
            if(devicePointer >= deviceCount) { devicePointer = 0; }
        }
        while(devices[devicePointer] != 1)
        {
            devicePointer++;
            if(devicePointer >= deviceCount) { devicePointer = 0;}
        }
        devices[devicePointer] = 0; 
    }
    while(devices[devicePointer] != 1)
    {
        devicePointer++;
        if(devicePointer >= deviceCount) { devicePointer = 0;}
    }  
    return devicePointer+1;
    
}

int main()
{
    powerOffAllButOne(5, 2);
    return 0;
}