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

        std::size_t kickpos = book.find("KICK");
        int luckyCount = 0;
        while(kickpos < book.size())
        {
            if(kickpos != std::string::npos)
            {
                std::size_t startpos = book.find("START", kickpos);
                while(startpos < book.size())
                {
                    if(startpos != std::string::npos)
                    {
                        luckyCount++;
                    }
                    startpos = book.find("START", startpos + 5);
                }
            }
            kickpos = book.find("KICK", kickpos + 3);
        }
        std::cout << "Case #" << t << ": " << luckyCount << std::endl;
    }
}