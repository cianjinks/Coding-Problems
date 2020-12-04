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

// Worst Case Complexity is O(N^2logN)
int threeSumMul(std::vector<int>& nums, int sum)
{
    // O(NlogN);
    std::sort(nums.begin(), nums.end());

    int index = -1;
    int num1 = 0;
    int num2 = 0;
    // O(N)
    for(; num1 < NUM_NUMS; num1++)
    {
        num2 = 0;
        // O(N)
        for(; num2 < NUM_NUMS; num2++)
            {
            // O(logN)
            index = binarySearch(nums, 2020-nums[num1]-nums[num2]);
            if(index != -1) { break; }
        }
        if(index != -1) { break; }
    }
    std::cout << nums[num1] << std::endl;
    std::cout << nums[num2] << std::endl;
    std::cout << nums[index] << std::endl;    
    return nums[num1] * nums[num2] * nums[index];
}

int main()
{
    std::vector<int> nums(NUM_NUMS, 0);
    for(int i = 0; i < NUM_NUMS; i++)
    {
        std::cin >> nums[i];
    }
    std::cout << threeSumMul(nums, 2020) << std::endl;
    return 0;
}