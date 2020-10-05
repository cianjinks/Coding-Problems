//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int firstUniqChar(std::string s) {
        int n = (int)s.size();
        std::unordered_map<char, int> map;
        for(int i = 0; i < n; i++)
        {
            map[s[i]]++;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(map[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    int i = s.firstUniqChar("leetcode");
    std::cout << i << std::endl;
    i = s.firstUniqChar("loveleetcode");
    std::cout << i << std::endl;
    return 0;
}