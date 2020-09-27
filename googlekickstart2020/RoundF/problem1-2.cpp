#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    for(int x = 1; x <= T; x++)
    {
        int N, X;
        std::cin >> N >> X;

        std::vector<std::pair<int, int>> queue;
        std::vector<int> leftqueue;

        for(int i = 0; i < N; i++)
        {
            int A;
            std::cin >> A;
            if(A <= X)
            {
                leftqueue.emplace_back(i + 1);
            }
            else
            {
                queue.emplace_back(i, A - X);
            }

        }

        while((int)leftqueue.size() < N)
        {
            for(int j = 0; j < queue.size(); j++)
            {
                if(queue[j].second <= X && queue[j].second > 0)
                {
                    leftqueue.emplace_back(queue[j].first + 1);
                    if((int)leftqueue.size() >= N)
                    {
                        break;
                    }
                }
                queue[j].second -= X;
            }
        }

        std::cout << "Case #" << x << ": ";
        for(int p = 0; p < (int)leftqueue.size(); p++)
        {
            std::cout << leftqueue[p] << " ";
        }
        std::cout << std::endl;
    }
}