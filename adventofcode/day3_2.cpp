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
    std::vector<int> treeCounts(5, 0);
    std::vector<std::pair<int, int>> routes = {std::pair<int, int>(1, 1), std::pair<int, int>(1, 3), std::pair<int, int>(1, 5), 
                                              std::pair<int, int>(1, 7), std::pair<int, int>(2, 1)};

    for(int i = 0; i < routes.size(); i++)
    {
        toboggan.first = 0;
        toboggan.second = 0;
        while(toboggan.first < NUM_LINES)
        {
            if(map[toboggan.first][toboggan.second] == '#')
            {
                treeCounts[i]++;
            }
            toboggan.second += routes[i].second;
            toboggan.first += routes[i].first;

            // Wrap around
            if(toboggan.second >= 31) { toboggan.second = toboggan.second - 31; }
        }
    }

    // Print out multiplcation of tree counts
    long treeCountMul = 1;
    for(int i = 0; i < treeCounts.size(); i++)
    {
        std::cout << "Tree Count for (" << routes[i].first << ", " << routes[i].second << "): " << treeCounts[i] << std::endl;
        treeCountMul *= treeCounts[i];
    }
    std::cout << "Tree Counts Multiplied: " << treeCountMul << std::endl;
    return 0;
}
