#include <iostream>
#include <string>

#if 1
int compute_difference(std::string I, std::string P)
{
    int p = 0;
    int i = 0;
    while(p < P.length() && i < I.length())
    {
        if (P[p] == I[i])
        {
            p++;
            i++;
        }
        else
        {
            p++;
        }
    }

    if (i == (int)I.length())
    {
        return P.length() - I.length();
    }

    return -1;
}
#elif
int compute_difference(std::string I, std::string P)
{
    int correct = 0;
    int p = 0;
    int i = 0;
    while (i < (int)I.length())
    {
        while(I[i] != P[p] && p < (int)P.length())
        {
            p++;
        }

        if (p == (int)P.length()) { break; }

        correct++;
        p++;
        i++;
    }

    if (correct == (int)I.length())
    {
        int test = P.length() - I.length();
        return test;
    }

    return -1;
}
#endif

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::string I, P;
        std::cin >> I;
        std::cin >> P;

        int result = compute_difference(I, P);
        if (result != -1)
        {
            std::cout << "Case #" << t << ": " << result << std::endl;
        }
        else
        {
            std::cout << "Case #" << t << ": " << "IMPOSSIBLE" << std::endl;
        }
    }
}