//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/
#include <iostream>
#include <string>
#include <vector>

// Attempt 1
/**
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()) { return false; }
        std::unordered_multiset<char> string1(s.begin(), s.end());
        std::unordered_multiset<char> string2(t.begin(), t.end());
        return string1 == string2;
    }
};**/

// Attempt 2
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()) { return false; }
        int n = (int)s.size();
        std::vector<int> bucket(26, 0);
        for(int i = 0; i < n; i++)
        {
            bucket[s[i]-'a']++;
            bucket[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(bucket[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    std::cout << s.isAnagram("nl", "cx") << std::endl;
    return 0;
}