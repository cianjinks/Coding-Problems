//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/727/

#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {

        // This function simply copies one copy of each non duplicate element to its respective position at the front of the array
        // but this leaves lots of extra elements at the end. However, since we return the size to be correct it dosen't matter
        if(nums.size() < 2) { return (int)nums.size(); }
        int i=0;   
        int j=1;
        while(j < (int)nums.size())
        {
            if(nums[i]==nums[j])
            {
                j++;
            }
            else{
                nums[i+1]=nums[j];
                i++;
                j++;
            }
        }
        return i+1;
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
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int size = s.removeDuplicates(nums);
    std::cout << "Array Size: " << size << std::endl;
    printArray(nums, size);
    return 0;
}