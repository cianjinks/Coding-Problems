// https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
    public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> numerals = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int count = 0;
        for (int c = 0; c < s.length(); c++)
        {
            if ((c < s.length() - 1) && numerals[s[c]] < numerals[s[c + 1]])
            {
                count -= numerals[s[c]];
            }
            else
            {
                count += numerals[s[c]];
            }
        }
    }
};

int main()
{
    Solution s;
}