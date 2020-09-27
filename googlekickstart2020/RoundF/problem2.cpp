#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int T;
    std::cin >> T;
    for(int x = 1; x <= T; x++)
    {
        int N, K;
        std::cin >> N >> K;
        std::vector<std::pair<int, int>> intervals;
        for(int i = 0; i < N; i++)
        {
            int S, E;
            std::cin >> S >> E;
            intervals.emplace_back(std::make_pair(S, E));
        }
        std::sort(intervals.begin(), intervals.end());
        int currentTime = intervals[0].first;
        int robotCount = 0;

        for(int j = 0; j < intervals.size(); j++)
        {
            if(intervals[j].first <= currentTime)
            {
                if(intervals[j].second > currentTime)
                {
                    //currentTime = intervals[j].first;
                    while(intervals[j].second > currentTime)
                    {
                        robotCount++;
                        currentTime += K;
                    }
                    continue;
                }
            }
            else
            {
                currentTime = intervals[j].first;
                j--;
                continue;
            }
        }
        std::cout << "Case #" << x << ": " << robotCount << std::endl;
    }
}