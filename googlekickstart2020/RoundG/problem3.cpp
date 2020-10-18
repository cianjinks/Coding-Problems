#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

// Brute Force Version
int main()
{
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++)
    {
        long long W, N;
        std::cin >> W >> N;

        std::vector<long long> combinationLock;

        for(long long i = 0; i < W; i++)
        {
            long long X;
            std::cin >> X;
            combinationLock.emplace_back(X);
        }

        long long smallestMove = std::numeric_limits<long long>::max();
        // Loop over all possible values
        for(long long i = 1; i <= N; i++)
        {
            // Check the number of moves for each value of the lock to reach i
            long long totalMoves = 0;
            for(long long j = 0; j < (long long)combinationLock.size(); j++)
            {
                // Find the smallest difference between X and the number we are trying to match
                long long noWrap = abs((combinationLock[j] - i));
                long long wrap; 
                if(i < (N / 2)) { wrap = abs((N - combinationLock[j] + i)); }
                else { wrap = abs((N - i + combinationLock[j])); }

                if(noWrap <= wrap)
                {
                    totalMoves += noWrap;
                }
                else
                {
                    totalMoves += wrap;
                }
            }
            // Check if this total is smallest
            if(totalMoves < smallestMove)
            {
                smallestMove = totalMoves;
            }
        }

        std::cout << "Case #" << t << ": " << smallestMove << std::endl;
    }
}