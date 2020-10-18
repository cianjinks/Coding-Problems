#include <iostream>
#include <string>
#include <vector>

int main()
{
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++)
    {
        std::string book;
        std::cin >> book;
        int luckyCount = 0;

        std::vector<std::size_t> kickPositions;
        std::vector<std::size_t> startPositions;

        size_t pos = book.find("KICK", 0);
        while(pos != std::string::npos)
        {
            kickPositions.emplace_back(pos);
            pos = book.find("KICK", pos+3);
        }

        pos = book.find("START", 0);
        while(pos != std::string::npos)
        {
            startPositions.emplace_back(pos);
            pos = book.find("START", pos+5);
        }
        
        for(size_t i = 0; i < kickPositions.size(); i++)
        {
            int beforeKick = 0;
            for(size_t j = 0; j < startPositions.size(); j++)
            {
                if(kickPositions[i] > startPositions[j])
                {
                    beforeKick++;
                }
            }
            luckyCount += (startPositions.size() - beforeKick);
        }

        std::cout << "Case #" << t << ": " << luckyCount << std::endl;
    }
}