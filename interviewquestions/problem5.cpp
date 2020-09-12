//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/549/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            num ^= nums[i];
        }
        return num;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {4,1,2,1,2};
    std::cout << "Single Number: " << s.singleNumber(nums) << std::endl;
}