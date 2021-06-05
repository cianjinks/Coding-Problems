#include <iostream>

int main()
{
   double array[10] = {1.943, 1.93, 1.943, 1.956, 1.918, 1.918, 1.876, 1.876, 1.905, 1.905};
   double mean = 0;
   double n = 10;

   for(int i = 0; i < 10; i++)
   {
      mean += array[i];
   }
   mean /= 10;
   std::cout << "MEAN: " << mean << std::endl;

   double summation = 0;
   for(int i = 0; i < 10; i++)
   {
      double diff = array[i] - mean;
      summation += diff * diff;
   }
   double result = summation / (n - 1);
   std::cout << result << std::endl;
}