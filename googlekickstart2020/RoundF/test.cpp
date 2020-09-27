#include <iostream>
#include <vector>
#include <string>

void printArray(std::vector<int>& nums)
{
    std::cout << "Array: ";
    for(auto& number : nums)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> nums;
    for(int i = 0; i < N; i++)
    {
        int j;
        std::cin >> j;
        nums.emplace_back(j);
    }

    printArray(nums);
}