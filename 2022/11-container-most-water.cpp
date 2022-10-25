// https://leetcode.com/problems/container-with-most-water/
#include <vector>
#include <iostream>

// Brute Force approach considering every pair of heights
#if 0
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int most_water = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = 0; j < height.size(); j++)
            {
                if (i != j)
                {
                    int water = std::min(height[i], height[j]) * std::abs(i - j);
                    if (most_water < water)
                    {
                        most_water = water;
                    }

                }
            }
        }
        return most_water;
    }
};
#endif

// Two pointer window closing in from both sides
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int most_water = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r)
        {
            int water = std::min(height[l], height[r]) * std::abs(l - r);
            if (most_water < water)
            {
                most_water = water;
            }

            if (height[l] < height[r]) { l++; }
            else { r--; }
        }
        return most_water;
    }
};

int main()
{
    Solution s;
    std::vector<int> test = {2,3,10,5,7,8,9};
    std::cout << s.maxArea(test) << std::endl;
}