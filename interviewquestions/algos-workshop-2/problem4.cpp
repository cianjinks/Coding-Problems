#include <iostream>
#include <vector>

void FizzBuzz(int N)
{
    for(int num = 1; num <= N; num++)
    {
        if(num % 3 == 0 && num % 5 == 0)
        {
            std::cout << "FizzBuzz" << " ";
        }
        else if(num % 3 == 0)
        {
            std::cout << "Fizz" << " ";
        }
        else if(num % 5 == 0)
        {
            std::cout << "Buzz" << " ";
        }
        else
        {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    FizzBuzz(10);
    FizzBuzz(30);
    FizzBuzz(6);
    FizzBuzz(15);
}