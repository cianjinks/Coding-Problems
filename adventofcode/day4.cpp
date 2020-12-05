#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

bool validatePassport(std::string passport)
{
    std::vector<std::string> fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

    int validFields = 0;
    size_t field_separator = passport.find(':');
    while(field_separator != std::string::npos)
    {
        std::string field = passport.substr(field_separator-3, field_separator);
        if(std::find(fields.begin(), fields.end(), field.substr(0, 3)) != fields.end())
        {
            field_separator = passport.find(':', field_separator+1);
            validFields++;
        }
        else if(field.substr(0, 3) == "cid")
        {
            field_separator = passport.find(':', field_separator+1);
            continue;
        }
        else
        {
            return false;
        }
    }
    return (validFields == 7);
}

int main()
{
    std::vector<std::string> passports;
    std::string passport;
    while(passport != "END")
    {
        std::string field;
        std::getline(std::cin, field);
        if(field == "")
        {
            passports.emplace_back(passport);
            passport = "";
        }
        else
        {
            passport += field;
        }
    }

    int validPassports = 0;
    for(int i = 0; i < (int)passports.size(); i++)
    {
        if(validatePassport(passports[i]))
        {
            validPassports++;
        }
    }
    std::cout << "Valid Passports: " << validPassports << std::endl;
    return 0;
}