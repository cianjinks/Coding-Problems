// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Better solution is to use sliding window!
#if 1
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) { return 0; }
        int longest = 1;
        // O(n^2)
        for (int i = 0; i < s.length(); i++)
        {
            std::unordered_set<char> substring;
            for (int j = i; j < s.length(); j++)
            {
                if (substring.find(s[j]) == substring.end())
                {
                    substring.insert(s[j]);
                }
                else
                {
                    break;
                }
            }
            if (longest < substring.size())
            {
                longest = substring.size();
            }
        }
        return longest;
    }
};
#else
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {

    }
};
#endif
int main()
{
    Solution s;
    std::vector<std::string> tests = {"au", "abcabcbb", "bbbbb", "pwwkew"};
    for (std::string& string : tests)
    {
        std::cout << string << ": " << s.lengthOfLongestSubstring(string) << std::endl;
    }
}