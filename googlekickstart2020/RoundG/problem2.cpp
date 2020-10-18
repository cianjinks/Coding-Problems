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
        std::vector<std::vector<int>> matrix(matrixSize, std::vector<int>(matrixSize, 0));
        for(int i = 0; i < matrixSize; i++)
        {
            for(int j = 0; j < matrixSize; j++)
            {
                std::cin >> matrix[i][j];
            }
        }

        // Count the value of each of the diagonals
        std::vector<int> diagonalValues;

        // Obtain all bottom left diagonals
        int numToSum = 0;
        while(numToSum < matrixSize-1)
        {
            int total = 0;
            for(int i = 0; i <= numToSum; i++)
            {
                total += matrix[matrixSize-numToSum+i-1][i];
            }
            diagonalValues.emplace_back(total);
            numToSum++;
        }

        // Obtain main diagonal
        int mainIndex = 0;
        int mainTotal = 0;
        while(mainIndex < matrixSize)
        {
            mainTotal += matrix[mainIndex][mainIndex];
            mainIndex++;
        }
        diagonalValues.emplace_back(mainTotal);

        // Obtain all top right diagonals
        numToSum = 0;
        while(numToSum < matrixSize-1)
        {
            int total = 0;
            for(int i = 0; i <= numToSum; i++)
            {
                total += matrix[i][matrixSize-numToSum+i-1];
            }
            diagonalValues.emplace_back(total);
            numToSum++;
        }

        // Find most amount of coins
        int largest = 0;
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