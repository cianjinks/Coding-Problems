//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/559/

#include <vector>
#include <iostream>
#include <algorithm>

// Solution 1:
/**
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = (int)digits.size();
        if(digits[n-1] == 9)
        {
            for(int i = n-1; i >= 0; i--)
            {
                if(digits[i] + 1 == 10)
                {
                    digits[i] = 0;
                }
                else
                {
                    digits[i]++;
                    break;
                }
                if(i == 0)
                {
                    digits.insert(digits.begin(), 1);
                }
                
            }
        }
        else
        {
            digits[n-1]++;
        }
        return digits;
    }
};
**/

// Optimised Solution:
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = (int)digits.size();
        for(int i = n-1; i >= 0; i--)
        {
            if(digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

void printArray(std::vector<int>& nums, int size)
{
    //std::cout << "Array Size: " << nums.size() << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Solution s;
    std::vector<int> data = {9};
    s.plusOne(data);
    printArray(data, data.size());
    return 0;
}