//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/
#include <iostream>
#include <string>
#include <vector>

// This question considers " " a palindrome despite the fact it also considers "A man, a plan, a canal: Panama" a palindrome with the spaces????
// I give up
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int n = (int)s.size();
        int i  = 0;
        int j = s.size() - 1;
        while(i < ((n-1)/2) || j > ((n-1)/2))
        {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }

    bool isPalindrome(std::string s) {
        std::vector<char> array(s.begin(), s.end());
        int n = (int)s.size();
        int i = 0;
        while(i < n)
        {
            if(array[i] < 65 || array[i] > 122)
            {
                array.erase(array.begin() + i);
                if(array.size() == 0)
                {
                    return true;
                }
                n--;
                i--;
            }
            if(array[i] > 64 && array[i] < 91)
            {
                array[i] += 32;
            }
            i++;
        }
        std::vector<char> reversed = array;
        reverseString(reversed);
        if(array == reversed)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};

int main()
{
    Solution s;
    std::cout << s.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    std::cout << s.isPalindrome(" ") << std::endl;
}