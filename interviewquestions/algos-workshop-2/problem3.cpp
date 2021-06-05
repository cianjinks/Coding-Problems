#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

void RemovePondRecursive(int x, int y, int* topology, int xSize, int ySize)
{
    if(x >= 0 && x < xSize && y >= 0 && y < ySize)
    {
        if(topology[x + xSize*y] == 0)
        {
            topology[x + xSize*y] = -1; // Mark off visited squares
            RemovePondRecursive(x+1, y, topology, xSize, ySize);
            RemovePondRecursive(x-1, y, topology, xSize, ySize);
            RemovePondRecursive(x, y+1, topology, xSize, ySize);
            RemovePondRecursive(x, y-1, topology, xSize, ySize);
        }
    }
}

int GetNumPonds(int* topology, int xSize, int ySize)
{
    int result = 0;
    for(int x = 0; x < xSize; x++)
    {
        for(int y = 0; y < ySize; y++)
        {
            if(topology[x + xSize*y] == 0)
            {
                RemovePondRecursive(x, y, topology, xSize, ySize);
                result++;
            }
        }
    }
    return result;
}

int main()
{
    const int xSize = 5;
    const int ySize = 4;
    int topology[ySize][xSize] = 
    {{0, 1, 0, 1, 2},
     {1, 0, 0, 1, 2},
     {1, 1, 0, 1, 2},
     {0, 1, 1, 1, 0}};
    std::cout << "Test 1" << std::endl;
    std::cout << "----------------" << std::endl;
    for(int y = 0; y < ySize; y++)
    {
        for(int x = 0; x < xSize; x++)
        {
            std::cout << topology[y][x] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "----------------" << std::endl;
    int numPonds = GetNumPonds((int*)topology, xSize, ySize);
    std::cout << "Num Ponds: " << numPonds << std::endl;
}