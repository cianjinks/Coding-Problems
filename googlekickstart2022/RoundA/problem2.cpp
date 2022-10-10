#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

/* NOTE: To pass test 2 I would need to read in the numbers as strings and do the first summation of digits by converting each digit from char to int.
 *       This would collapse the number back to normal size straight away and can use ints from there.
 */

int create_from_digits(std::vector<int>& digits)
{
    int result = 0;
    for (int d = 0; d < digits.size(); d++)
    {
        result *= 10;
        result += digits[d];
    }
    return result;
}

std::vector<int> get_digits(int n)
{
    std::vector<int> digits;
    while(n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

int solution(int N)
{
    std::vector<int> og_digits = get_digits(N);

    /* Compute recursive digits until we have one left. */
    std::vector<int> digits(og_digits.begin(), og_digits.end());
    while(digits.size() != 1)
    {
        int sum = 0;
        for (int d : digits)
        {
            sum += d;
        }
        digits = get_digits(sum);
    }
    /* Calculate digit we need to add to the original number. */
    int digit_to_add = 9 - digits[0];

    /* Loop from front of number and insert digit before largest digit. This will give the smallest number. */
    std::reverse(og_digits.begin(), og_digits.end());
    int i = 0;
    for (; i < og_digits.size(); i++)
    {
        if (digit_to_add < og_digits[i])
        {
            if (i == 0 && digit_to_add == 0) { continue; } /* No leading 0's. */
            og_digits.insert(og_digits.begin() + i, digit_to_add);
            break;
        }
    }
    if (i == og_digits.size())
    {
        og_digits.push_back(digit_to_add);
    }

    return create_from_digits(og_digits);
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        std::cin >> N;
        int result = solution(N);
        std::cout << "Case #" << t << ": " << result << std::endl;
    }
}