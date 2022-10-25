#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>

std::string create_from_digits(std::vector<int> &digits)
{
    std::string s = "";
    for (int d : digits)
    {
        s += std::to_string(d);
    }
    return s;
}

std::vector<int> get_digits(std::string n)
{
    std::vector<int> digits;
    for (char c : n)
    {
        digits.push_back(c - '0');
    }
    return digits;
}

std::string solution(std::string N)
{
    std::vector<int> digits = get_digits(N);

    /* Calculate sum of digits. */
    // O(log10(n))
    int sum = 0;
    for (int d : digits)
    {
        sum += d;
    }

    /* Calculate digit we need to add to the original number. */
    int mod = sum % 9;
    int digit_to_add = 0;
    if (mod)
    {
        digit_to_add = 9 - (sum % 9);
    }

    /* Loop from front of number and insert digit before largest digit. This will give the smallest number. */
    // O(log10(n))
    int i = 0;
    for (; i < digits.size(); i++)
    {
        if (digit_to_add < digits[i])
        {
            if (i == 0 && digit_to_add == 0) /* No leading 0's. */
            {
                continue;
            }
            digits.insert(digits.begin() + i, digit_to_add);
            break;
        }
    }
    if (i == digits.size())
    {
        digits.push_back(digit_to_add);
    }

    return create_from_digits(digits);
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::string N;
        std::cin >> N;
        std::string result = solution(N);
        std::cout << "Case #" << t << ": " << result << std::endl;
    }
}