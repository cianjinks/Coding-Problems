//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/769/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>


void printArray(std::vector<char>& array, int size)
{
    //std::cout << 'Array Size: ' << nums.size() << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

// Solution 1:
/**
class Solution {
public:
    bool containsDuplicate(std::vector<char> array) {
        std::sort(array.begin(), array.end());
        printArray(array, array.size());
        std::unordered_set<char> set;
        int dots = 0;
        for(auto& character : array)
        {
            if(character != '.')
            {
                set.emplace(character);
            }
            else { dots++; }
        }
        return set.size() < (array.size() - dots);
    }

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Check every row
        for(int x = 0; x < 9; x++)
        {
            if(containsDuplicate(board[x]))
            {
                return false;
            }
        }

        std::cout<<std::endl;

        // Check every column
        for(int x = 0; x < 9; x++)
        {
            std::vector<char> column;
            for(int y = 0; y < 9; y++)
            {
                column.emplace_back(board[y][x]);
            }

            if(containsDuplicate(column))
            {
                return false;
            }
        }

        std::cout<<std::endl;

        int yLimit = 0;
        // Check all sub boxes
        for(int k = 0; k < 3; k++)
        {
            int xLimit = 0;
            // Check first 3 sub boxes
            for(int i = 0; i < 3; i++)
            {
                std::vector<char> subbox;
                for(int x = xLimit; x < (xLimit + 3); x++)
                {
                    for(int y = yLimit; y < (yLimit + 3); y++)
                    {
                        subbox.emplace_back(board[x][y]);
                    }
                }

                if(containsDuplicate(subbox))
                {
                    return false;
                }
                xLimit += 3;
            }
            std::cout<<std::endl;
            yLimit += 3;
        }
        return true;
    }
};
**/

// Optimised Solution:


int main()
{
    Solution s;
    std::vector<std::vector<char>> board
    = 
    {
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}
    };
    bool result = s.isValidSudoku(board);
    std::cout << result << std::endl;
    return 0;
}