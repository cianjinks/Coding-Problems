// Set Matrix Zeroes
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        bool isCol = false;
        int R = matrix.size();
        int C = matrix[0].size();

        for (int i = 0; i < R; i++)
        {
            if (matrix[i][0] == 0)
            {
                isCol = true;
            }

            for (int j = 1; j < C; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < R; i++)
        {
            for (int j = 1; j < C; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < C; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (isCol)
        {
            for (int i = 0; i < R; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }

    void printMatrix(std::vector<std::vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Solution s;
    // std::vector<std::vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    // s.setZeroes(matrix);
    // s.printMatrix(matrix);
    std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    s.setZeroes(matrix);
    s.printMatrix(matrix);
}