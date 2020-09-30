//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/674/

#include <vector>
#include <iostream>
#include <algorithm>

// Solution 1:
/**
class Solution
{
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = (int)nums1.size();
        int n2 = (int)nums2.size();

        if(n1 == 0 || n2 == 0)
        {
            return std::vector<int>(0);
        }

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> result;

        for(int i = 0; i < n1; i++)
        {
            // if array does contain the integer add it
            auto found = std::find(nums2.begin(), nums2.end(), nums1[i]);
            if(found != nums2.end())
            {
                result.emplace_back(nums1[i]);
                nums1.erase(nums1.begin() + i);
                n1--;
                i--;
                nums2.erase(found);
                n2--;
            }
        }
        return result;
    }
};
**/

class Solution
{
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {

        int n1 = (int)nums1.size();
        int n2 = (int)nums2.size();

        if(n1 == 0 || n2 == 0)
        {
            return std::vector<int>(0);
        }

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> result;
        
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j])
                j++;
            else
                i++;
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
    std::vector<int> array1 = {1, 2, 2, 1};
    std::vector<int> array2 = {2};
    std::vector<int> array3 = s.intersect(array1, array2);
    printArray(array3, array3.size());
    return 0;
}