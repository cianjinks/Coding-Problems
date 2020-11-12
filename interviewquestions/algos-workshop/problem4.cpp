//FizzBuzz
#include <iostream>

void fizzBuzz(int N)
{
    for(int i = 1; i <= N; i++)
    {
        if(i % 3 == 0)
        {
            if(i % 5 == 0)
            {
                std::cout << "FizzBuzz ";
            }
            else 
            {
                std::cout << "Fizz ";
            }
        }
        else if(i % 5 == 0)
        {
            std::cout << "Buzz ";
        }
        else 
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    fizzBuzz(15);
    return 0;
}