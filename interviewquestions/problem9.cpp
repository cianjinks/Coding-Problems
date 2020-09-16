//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/546/

#include <vector>
#include <iostream>
#include <algorithm>

// Solution 1:
class Solution {
public:
    // Find which two numbers add up to target
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = (int)nums.size();

        std::vector<int> result;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                {
                    continue;
                }
                if(nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
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
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    std::vector<int> result = s.twoSum(nums, target);
    printArray(result, result.size());
    return 0;
}