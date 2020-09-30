//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/646/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    // Solution 1
    void rotate(std::vector<int>& nums, int k) {
        // This is the same as k %= nums.size();
        //if(k > nums.size()) {
        //    k -= nums.size();
        //}
        k %= nums.size();
        if(nums.size() > 1) {
            std::reverse(nums.begin(), nums.end());
            std::reverse(nums.begin(), nums.begin() + k);
            std::reverse(nums.begin() + k, nums.end());
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
    std::vector<int> nums = {1,2,3,4,5,6,7};
    int k = 2;
    s.rotate(nums, k);
    printArray(nums, nums.size());
    return 0;
}