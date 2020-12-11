// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/780/
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if(s.size() == 1) { return s; }
        if(s.size() == 2) 
        {
            if(s[0] == s[1]) { return std::string(s.begin(), s.begin() + 2); } 
            return std::string(s.begin(), s.begin() + 1); 
        }

        std::vector<char> array(s.begin(), s.end());

        std::vector<std::vector<char>> palindromes;
        for(int i = 0; i < array.size(); i++)
        {
            for(int j = array.size()-1; j >= i+1; j--)
            {
                int copyI = i;
                int copyJ = j;
                std::vector<char> string(array.begin() + i, array.begin() + j + 1);
                if(array[i] == array[j])
                {
                    while(i <= j)
                    {
                        if(array[i] != array[j]) { break; }
                        i++;
                        j--;
                    }
                    if(i > j) { palindromes.push_back(string); };
                }
                i = copyI;
                j = copyJ;
            }
        }

        if(palindromes.empty()) { return std::string(s.begin(), s.begin() + 1); };

        int maxPalindrome = 0;
        int maxPalindromeIndex = 0;
        for(int i = 0; i < palindromes.size(); i++)
        {
            if(palindromes[i].size() > maxPalindrome)
            {
                maxPalindrome = palindromes[i].size();
                maxPalindromeIndex = i;
            }
        }
        return std::string(palindromes[maxPalindromeIndex].begin(), palindromes[maxPalindromeIndex].end());
    }
};

int main()
{
    Solution s;
    std::string result = s.longestPalindrome("abcda");
    std::cout << result << std::endl;
    return 0;
}