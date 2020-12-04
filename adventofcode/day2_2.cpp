#include <iostream>
#include <algorithm>
#include <vector>

// This problem can probably be solved with regex so note to self to learn that
int countCorrectPasswords(std::vector<std::string>& passwords)
{
    int correct = 0;
    for(int i = 0; i < 3000; i+=3)
    {
        std::pair<int, int> range(-1, -1);
        size_t hyphen = passwords[i].find('-');
        range.first = std::stoi(passwords[i].substr(0, hyphen)); 
        range.second = std::stoi(passwords[i].substr(hyphen+1, passwords[i].size())); 

        char character = passwords[i + 1][0];

        std::string password = passwords[i + 2];
        bool correctPassword = false;
        for(int j = 0; j < password.size(); j++)
        {
            if(j == range.first-1 || j == range.second-1)
            {
                if(password[j] == character)
                {
                    correctPassword = !correctPassword;
                }
            }
        }
        if(correctPassword)
        {
            correct++;
        }
    }
    return correct;
}

int main()
{
    std::vector<std::string> passwords(3000);
    for(int t = 0; t < 3000; t++)
    {
        std::cin >> passwords[t];
    }
    std::cout << "Correct Passwords: " << countCorrectPasswords(passwords) << std::endl;
}