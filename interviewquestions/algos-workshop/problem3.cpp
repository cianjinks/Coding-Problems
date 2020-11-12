#include <iostream>
#include <vector>
// Number of Ponds in a body of water

void recursePond(std::vector<std::vector<int>>& land, int x, int y)
{
    if(x >= 0 && x < land.size() && y >= 0 && y < land[0].size())
    {
        if(land[x][y] == 0)
        {
            land[x][y] = -1;
            recursePond(land, x+1, y);
            recursePond(land, x-1, y);
            recursePond(land, x, y+1);
            recursePond(land, x, y-1);
        }
    }
}

int countPonds(std::vector<std::vector<int>>& land)
{
    int ponds = 0;
    for(int x = 0; x < land.size(); x++)
    {
        for(int y = 0; y < land[0].size(); y++)
        {
            if(land[x][y] == 0)
            {
                recursePond(land, x, y);
                ponds++;
            }
        }
    }
    return ponds;
}

int main()
{
    std::vector<std::vector<int>> land;
    land.emplace_back(std::vector<int>{0, 1, 0, 1, 2});
    land.emplace_back(std::vector<int>{1, 0, 0, 1, 2});
    land.emplace_back(std::vector<int>{1, 1, 0, 1, 2});
    land.emplace_back(std::vector<int>{0, 1, 1, 1, 0});
    int result = countPonds(land);
    std::cout << result << std::endl;
    return 0;
}