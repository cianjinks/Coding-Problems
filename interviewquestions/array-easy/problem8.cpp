//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/567/

#include <vector>
#include <iostream>
#include <algorithm>

// Solution 1:
/**
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        int moved = 0;
        for(int i = 0; i < (n - moved - 1); i++) 
        {
            if(nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                nums.emplace_back(0);
                moved++;
                i--;
            }
        }
    }
};
**/

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        for(int i = 0, zeroes = 0; i < n; i++) 
        {
            if(nums[i] != 0)
            {
                std::swap(nums[i], nums[zeroes++]);
            }
        }
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
    std::vector<int> nums = {0,0,1};
    s.moveZeroes(nums);
    printArray(nums, nums.size());
    return 0;
}