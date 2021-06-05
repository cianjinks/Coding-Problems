#include <iostream>
#include <vector>

std::vector<int> GetDivingBoardLengths(int N, int X, int Y)
{
    std::vector<int> divingBoardLengths;
    // O(N)
    for(int i = 0; i <= N; i++)
    {
        int boardLength = X*(N-i) + (Y*i); // Algorithm for getting board length based on writing out
        divingBoardLengths.emplace_back(boardLength);
    }
    return divingBoardLengths;
}

int main()
{
    std::cout << "Test 1" << std::endl;
    std::vector<int> result = GetDivingBoardLengths(6, 3, 2);
    for(int i = 0; i < (int)result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    std::cout << "Test 2" << std::endl;
    result = GetDivingBoardLengths(6, 4, 2);
    for(int i = 0; i < (int)result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    std::cout << "Test 3" << std::endl;
    result = GetDivingBoardLengths(6, 7, 1);
    for(int i = 0; i < (int)result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
}