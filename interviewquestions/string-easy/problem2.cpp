#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string reverseString(std::vector<char> s) {
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
        return std::string(s.begin(), s.end());
    }
    int reverse(int x) {
        bool negative = x < 0;
        std::string xString = std::to_string(x);
        std::string result = reverseString(std::vector<char>(xString.begin(), xString.end()));
        if(negative)
        {
            try { return -std::stoi(result); }
            catch(const std::exception& e)
            { return 0; }
        }

        try { return std::stoi(result); }
        catch(const std::exception& e)
        { return 0; }
    }
};

void printResult(int x)
{
    Solution s;
    std::cout << "Number: " << x << std::endl;
    x = s.reverse(x);
    std::cout << "Reversed: " << x << std::endl;
}

int main()
{
    Solution s;
    int x = 123;
    printResult(x);

    x = -123;
    printResult(x);

    x = 0;
    printResult(x);

    // Overflow
    x = 2147483647;
    printResult(x);
    return 0;
}