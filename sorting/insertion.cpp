#include <iostream>

void InsertionSort(int *array, int length)
{
    for(int i = 1; i < length; i++)
    {
        if(array[i-1] > array[i])
        {
            // Insert into sorted array section
            int k = i;
            while(array[k-1] > array[k] && k > 0)
            {
                int tmp = array[k-1];
                array[k-1] = array[k];
                array[k] = tmp;
                k--;
            }
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
    int array[length] = {1, 4, 5, 6, 2, 7, 8};
    PrintArray(array, length);
    InsertionSort(array, length);
    PrintArray(array, length);
    return 0;
}