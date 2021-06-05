#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

#define ASCII_OFFSET 97
#define SIZE_OF_ALPHABET 26

// Time Complexity: Max(O(N), O(M)) | Space Complexity: O(N) | N is size of alphabet, M is size of input word
bool hasPalindromePermutation(std::string word)
{
    if(word.size() < 2) { return true; }

    // Words are exclusively a to z and lower case (as stated)
    // Array to store counts of each letter
    int letters[SIZE_OF_ALPHABET] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

    for(int i = 0; i < word.size(); i++)
    {
        letters[word[i] - ASCII_OFFSET]++; // Count up each letter
    }

    // If the word is odd length we can ignore one wrong letter count
    bool oddUsed = false;
    if(word.size() % 2 == 0) { oddUsed = true; }

    // Check for all letters of count 2 except one if odd
    for(int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if(letters[i] != 0 && letters[i] != 2)
        {
            if(oddUsed) { return false; } 
            else { oddUsed = true; }
        }
    }
    return true;
}

int main()
{
    std::cout << "Tests" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "civic: " << hasPalindromePermutation("civic") << std::endl;
    std::cout << "test: " << hasPalindromePermutation("test") << std::endl;
    std::cout << "block: " << hasPalindromePermutation("block") << std::endl;
    std::cout << "level: " << hasPalindromePermutation("level") << std::endl;
    std::cout << "bacabc: " << hasPalindromePermutation("bacabc") << std::endl;
    std::cout << "a: " << hasPalindromePermutation("a") << std::endl;
    std::cout << ": " << hasPalindromePermutation("") << std::endl;
}