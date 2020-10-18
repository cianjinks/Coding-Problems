// Optimisied Version of problem 2

#include <iostream>
#include <string>
#include <vector>

int main()
{
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int matrixSize;
        std::cin >> matrixSize;

        // Load in Matrix
        std::vector<std::vector<long long>> matrix(matrixSize, std::vector<long long>(matrixSize, 0));
        for(int i = 0; i < matrixSize; i++)
        {
            for(int j = 0; j < matrixSize; j++)
            {
                std::cin >> matrix[i][j];
            }
        }

        // Count the value of each of the diagonals
        std::vector<long long> diagonalValues;

        // Obtain all diagonals except main
        int numToSum = 0;
        while(numToSum < matrixSize-1)
        {
            long long bottomtotal = 0;
            long long toptotal = 0;
            for(int i = 0; i <= numToSum; i++)
            {
                bottomtotal += matrix[matrixSize-numToSum+i-1][i];
                toptotal += matrix[i][matrixSize-numToSum+i-1];
            }
            diagonalValues.emplace_back(bottomtotal);
            diagonalValues.emplace_back(toptotal);
            numToSum++;
        }

        // Obtain main diagonal
        int mainIndex = 0;
        long long mainTotal = 0;
        while(mainIndex < matrixSize)
        {
            mainTotal += matrix[mainIndex][mainIndex];
            mainIndex++;
        }
        diagonalValues.emplace_back(mainTotal);

        // Find most amount of coins
        long long largest = 0;
        for(size_t i = 0; i < diagonalValues.size(); i++)
        {
            if(diagonalValues[i] > largest)
            {
                largest = diagonalValues[i];
            }
        }

        std::cout << "Case #" << t << ": " << largest << std::endl;
    }
}