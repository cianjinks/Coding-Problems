// 3 Sum
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        // 0, 0, 0, 0
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            // Skip duplicates
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {0, 0, 0, 0};
    std::vector<std::vector<int>> result = s.threeSum(nums);
    for (std::vector<int> &r : result)
    {
        printf("(%d, %d, %d) ", r[0], r[1], r[2]);
    }
    std::cout << std::endl;
}