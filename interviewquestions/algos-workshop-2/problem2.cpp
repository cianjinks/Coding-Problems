#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

std::vector<std::string> GetAnagrams(std::vector<std::string>& dictionary, std::string inputWord)
{
    std::vector<std::string> anagrams;

    // Sort the word
    std::sort(inputWord.begin(), inputWord.end());

    // Loop over words in the dictionary
    int D = dictionary.size();
    int W = inputWord.size();
    for(int i = 0; i < D; i++)
    {
        int wordSize = dictionary[i].size();
        if(W == wordSize) // Save alot of time by ignoring words of not same length
        {
            std::string wordCopy = dictionary[i]; // Copy word for sorting
            std::sort(wordCopy.begin(), wordCopy.end());
            if(wordCopy == inputWord) // == operator will compare vectors element by element
            {
                anagrams.emplace_back(dictionary[i]);
            }
        }
    }
    return anagrams;
}

int main()
{
    std::vector<std::string> dictionary = {"tips", "blah", "spit", "pits", "test"};
    std::string word = "tips";
    std::cout << "Test 1" << std::endl;
    std::cout << "---------------" << std::endl;
    std::vector<std::string> result = GetAnagrams(dictionary, word);
    for(int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
    std::cout << std::endl;

    dictionary = {"wordy", "fast", "speed", "lame", "test", "meal"};
    word = "meal";
    std::cout << "Test 2" << std::endl;
    std::cout << "---------------" << std::endl;
    result = GetAnagrams(dictionary, word);
    for(int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
}