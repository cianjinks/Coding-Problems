#include <iostream>
#include <vector>

std::vector<int> getBoards(int N, int X, int Y)
{
    std::vector<int> result;
    int size = 0;
    // The number of possible diving boards is N
    for(int i = 0; i <= N; i++)
    {
        // Each interation increase long boards and decrease short boards
        size = ((N-i) * Y) + i*X;
        result.emplace_back(size);
    }
    return result;
}

int main()
{
    int numBoards = 6, X = 3, Y = 2;
    std::vector<int> results = getBoards(numBoards, X, Y);
    for(int i = 0; i <= numBoards; i++)
    {
        std::cout << results[i] << std::endl;
    }
    return 0;
}