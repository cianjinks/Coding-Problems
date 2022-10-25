#include <vector>
#include <iostream>

int buildings_facing_sun(std::vector<int>& buildings)
{
    int result = 0;
    int min = 0;
    // O(n)
    for (int b : buildings)
    {
        if (b > min)
        {
            result++;
            min = b;
        }
    }
    return result;
}

int main()
{
    // std::vector<int> buildings = {7, 4, 8, 2, 9};
    std::vector<int> buildings = {2, 3, 4, 5};
    int result = buildings_facing_sun(buildings);
    std::cout << "Result: " << result << std::endl;
}