//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/578/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    // Solution 1:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for(auto& num : nums)
        {
            set.emplace(num);
        }
        return set.size() < nums.size();
    }
    /** Solution 2:
    bool containsDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        if(n < 2) { return false; }
        
        int minelement = *std::min_element(nums.begin(), nums.end());
        int maxelement = *std::max_element(nums.begin(), nums.end());

        std::vector<int> array;
        int size = maxelement - minelement + 1;
        for(int j = 0; j < size; j++)
        {
            array.emplace_back(0);
        }

        for(int i = 0; i < n; i++)
        {
            array[nums[i] - minelement]++;
            if(array[nums[i] - minelement] > 1) { return true; }
        }
        return false;
    }**/
};

int main()
{
    Solution s;
    std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    std::cout << "Contains Duplicate: " << s.containsDuplicate(nums) << std::endl;
    return 0;
}