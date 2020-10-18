//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
#include <iostream>
#include <vector>

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
};

int main()
{
    Solution s;
    std::vector<char> test = {'H',  'e', 'l', 'l', 'o'};
    s.reverseString(test);
    for(char c : test)
    {
        std::cout << c;
    }
    std::cout << std::endl;
    return 0;
}