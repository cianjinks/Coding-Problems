#include <iostream>
#include <vector>
#include <string>

int main()
{
    int T;
    std::cin >> T;
    for(int x = 1; x <= T; x++)
    {
        int S, C;
        std::pair<int, int> APos, BPos;
        std::cin >> S >> APos.first >> APos.second >> BPos.first >> BPos.second >> C;
        
        std::vector<std::pair<int, int>> closedRooms;

        int bestScore;
        if(C == 0)
        {
            // if B in middle
            if(BPos.first == 2 && BPos.second == 2)
            {
                bestScore = -1;
            }
            // if A in middle
            else if(APos.first == 2 && APos.second == 2)
            {
                bestScore = 1;
            }
            else
            {
                bestScore = 2;
            }
        }
        else if(C == 1)
        {
            int Ri, Pi;
            std::cin >> Ri >> Pi;
            closedRooms.emplace_back(std::make_pair(Ri, Pi));
            
            // If closed room is middle
            if(closedRooms[0].first == 2 && closedRooms[0].second == 2)
            {
                bestScore = 0;
            }
            else
            {
                // If B in middle
                if(BPos.first == 2 && BPos.second == 2)
                {
                    bestScore = -1;
                }
                else
                {
                    bestScore = 1;
                }
            }
        }
        else if(C == 2)
        {
            int Ri, Pi;
            std::cin >> Ri >> Pi;
            closedRooms.emplace_back(std::make_pair(Ri, Pi));
            std::cin >> Ri >> Pi;
            closedRooms.emplace_back(std::make_pair(Ri, Pi));

            bestScore = 0;
        }
        std::cout << "Case #" << x << ": " << bestScore << std::endl;
    }
}