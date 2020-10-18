// Practice Attempt while practicing for Round G
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int N, X;
        std::cin >> N >> X;
        std::vector<int> queue;
        std::vector<int> queueCopy;
        for(int i = 0; i < N; i++)
        {
            int A;
            std::cin >> A;
            queue.emplace_back(A);
            queueCopy.emplace_back(ceil(A / 2));
        }
        std::sort(queueCopy.begin(), queueCopy.end());

        std::cout << "Case #" << t << ": ";
        for(int i = 0; i < queue.size(); i++)
        {
            for(int j = 0; j < queueCopy.size(); j++)
            {
                if(ceil(queue[i] / 2) == queueCopy[j])
                {
                    std::cout << j+1;
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
