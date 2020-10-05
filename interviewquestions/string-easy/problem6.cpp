//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/

#include <string>
#include <vector>

class Solution {
public:
    int myAtoi(std::string s) {
        std::vector<char> string(s.begin(), s.end());
        int sign = 1;
        int result = 0;
        int i = 0;
        while(i < string.size())
        {
            if(string[i] == ' ')
            {
                string.erase(string.begin() + i);
                i--;
            }
            else if(string[i] == '+')
            {
                sign = 1;
            }
            else if(string[i] == '-')
            {
                sign = -1;
            }
            else if(string[i] >= 48 || string[i] <= 57)
            {
                int addition = (string[i] - 48) * (10 * (string.size() - i));
                int addSign = addition >= 0 ? 1 : 0;
                int resultSign = result >= 0 ? 1 : 0;
                result += addition;
                int newResultSign = result >= 0 ? 1 : 0;
                if(addSign == resultSign && resultSign != newResultSign)
                {
                    if(newResultSign >= 0)
                    {
                        return INT32_MAX;
                    }
                    else if(newResultSign <= 1)
                    {
                        return INT32_MIN;
                    }
                }
            }
            i++;
        }
    }
};

int main()
{
    
}