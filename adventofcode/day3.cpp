#include <iostream>
#include <vector>

#define NUM_LINES 323

int main()
{
    char map[NUM_LINES][31];
    for(int i = 0; i < NUM_LINES; i++)
    {
        std::string line;
        std::cin >> line;
        for(int j = 0; j < (int)line.size(); j++)
        {
            map[i][j] = line[j];
        }
    }

    std::pair<int, int> toboggan(0, 0);
    int treeCount = 0;

    while(toboggan.first < NUM_LINES)
    {
        if(map[toboggan.first][toboggan.second] == '#')
        {
            treeCount++;
        }
        toboggan.second += 3;
        toboggan.first += 1;

        // Wrap around
        if(toboggan.second >= 31) { toboggan.second = toboggan.second - 31; }
    }
    std::cout << "Tree Count: " << treeCount << std::endl;
    return 0;
}