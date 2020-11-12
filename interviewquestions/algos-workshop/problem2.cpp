#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isAnagram(std::string A, std::string B)
{
    if(A.size() != B.size()) { return false; }
    // Sort in O(nlogn)
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    // O(n)
    if(A == B)
    {
        return true;
    }
    return false;
}

std::vector<std::string> getAnagrams(std::vector<std::string>& dictionary, std::string word)
{
    std::vector<std::string> result;
    // Loop over entire dictionary
    // O(n)
    for(std::string& dictword : dictionary)
    {
        // Check if dictword is anagram
        // O(nlogn) however it is relative to the size of the words
        if(isAnagram(dictword, word))
        {
            result.emplace_back(dictword);
        }
    }
    return result;
}

int main()
{
    std::vector<std::string> dictionary;
    dictionary.emplace_back("tips");
    dictionary.emplace_back("spit");
    dictionary.emplace_back("pits");
    dictionary.emplace_back("pips");

    std::vector<std::string> result = getAnagrams(dictionary, "tips");
    for(std::string& word : result)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}