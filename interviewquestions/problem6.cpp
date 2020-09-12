//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/674/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        
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
    std::vector<int> array1 = {4,9,5};
    std::vector<int> array2 = {9,4,9,8,4};
    std::vector<int> array3 = s.intersect(array1, array2);
    printArray(array3, array3.size());
    return 0;
}