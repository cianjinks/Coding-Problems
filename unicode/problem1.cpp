#include <string>
#include <iostream>
#include <vector>

std::string Halliday(std::string message)
{
    for(int i = 0; i < message.size(); i++)
    {
        if(message[i] >= 65 && message[i] <= 90)
        {
            unsigned char result = message[i] + 13;
            if(result >= 91)
            {
                result = (result - 91) + 65; 
            }
            message[i] = result;
        }
        else if(message[i] >= 97 && message[i] <= 122)
        {
            unsigned char result = message[i] + 13;
            if(result >= 123)
            {
                result = (result - 123) + 97; 
            }
            message[i] = result;
        }
    }
    return message;
}

int main()
{
    std::string result = Halliday("Crystal Key");
    std::cout << result << std::endl;
    return 0;
}