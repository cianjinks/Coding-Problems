#include <iostream>
#include <vector>
#include <algorithm>

#define NUM_NUMS 200

int binarySearch(std::vector<int>& sorted, int num)
{
    int low = 0, high = NUM_NUMS-1;
    while(low <= high)
    {
        int middle = low + ((high - low)/2);
        if(sorted[middle] < num)
        {
            low = middle + 1;
        }
        else if(sorted[middle] > num)
        {
            high = middle - 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

// Worst Case Complexity is O(NlogN)
int twoSumMul(std::vector<int>& nums, int sum)
{
    // O(NlogN);
    std::sort(nums.begin(), nums.end());

    // O(N)
    int index = -1;
    int num = 0;
    for(; num < NUM_NUMS; num++)
    {
        // O(logN)
        index = binarySearch(nums, 2020-nums[num]);
        if(index != -1) { break; }
    }
    std::cout << nums[num] << std::endl;
    std::cout << nums[index] << std::endl;
    return nums[num] * nums[index];
}

int main()
{
    std::vector<int> nums(NUM_NUMS, 0);
    for(int i = 0; i < NUM_NUMS; i++)
    {
        std::cin >> nums[i];
    }
    std::cout << twoSumMul(nums, 2020) << std::endl;
    return 0;
}