#include <iostream>

void InsertionSort(int *array, int length)
{
    for(int i = 1; i < length; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(array[j-1] > array[j])
            {
                int tmp = array[j-1];
                array[j-1] = array[j];
                array[j] = tmp;
            }
            else { break; }
        }
    }
}

void PrintArray(int *array, int length)
{
    std::cout << "Printing Array: ";
    for(int i = 0; i < length-1; i++)
    {  
        std::cout << array[i] << ", ";
    }
    std::cout << array[length-1] << std::endl;
}

int main()
{
    const int length = 7;
    int array[length] = {1, 6, 5, 3, 2, 7, 8};
    PrintArray(array, length);
    InsertionSort(array, length);
    PrintArray(array, length);
    return 0;
}