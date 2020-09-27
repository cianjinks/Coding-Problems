#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>

int main()
{
    int T;
    std::cin >> T;
    for(int i = 1; i <= T; i++)
    {
        int N, X;
        std::cin >> N;
        std::cin >> X;
        // person number, amount
        std::queue<std::pair<int, int>> queue;
        std::vector<int> leftqueue;
        for(int j = 1; j <= N; j++)
        {
            int k;
            std::cin >> k;
            queue.emplace(std::make_pair(j, k));
        }


        while(leftqueue.size() < N)
        {
            if(queue.front().second <= X)
            {
                leftqueue.emplace_back(queue.front().first);
                queue.pop();
            }
            else
            {
                queue.front().second -= X;
                std::pair<int, int> temp = queue.front();
                queue.pop();
                queue.emplace(temp);
            }
        }

        std::cout << "Case #" << i << ": ";
        for(int p = 0; p < (int)leftqueue.size(); p++)
        {
            std::cout << leftqueue[p] << " ";
        }
        std::cout << std::endl;
    }
}