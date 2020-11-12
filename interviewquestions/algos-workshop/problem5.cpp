// Plaindrome
#include <string>
#include <iostream>
#include <algorithm>

bool palindromePermutation(std::string word)
{
    if(word.empty()) { return false; }
    if(word.size() == 1) { return true; }

    // Count the number of pairs in the array
    // O(n^2)
    std::vector<std::pair<char, char>> pairs;
    for(int i = 0; i < word.size(); i++)
    {
        for(int j = 0; j < word.size(); j++)
        {
            if(i != j)
            {
                if(tolower(word[i]) == tolower(word[j]))
                {
                    pairs.emplace_back(std::make_pair(word[i], word[j]));
                }
            }
        }
    }

    // Check if the word is even or odd in length and compare to the number of pairs
    if(word.size() % 2 == 0)
    {
        if(pairs.size() == word.size())
        {
            return true;
        }
        return false;
    }
    else if(pairs.size()+1 == word.size())
    {
        return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    std::cout << palindromePermutation("ciic12") << std::endl;
    return 0;
}