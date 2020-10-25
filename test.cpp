#include <iostream>
#include <bitset>
#include <cstdlib>

// Generate Decoder VHDL
/**
int main()
{
   for(int i = 0; i < 32; i++)
   {
      std::bitset<5> x(i);
      std::cout << "when \"" << x << "\" => Q <= \"";
      for(int j = 0; j < 32; j++)
      {
         if(j != (31 - i)) {
            std::cout << 0;
         } else {
            std::cout << 1;
         }
      }
      std::cout << "\" after 5ns;\n";
   }
   return 0;
}
**/

// Generate Multiplexer VHDL
/**
int main()
{
   for(int i = 0; i < 32; i++)
   {
      std::bitset<5> x(i);
      std::cout << "when \"" << x << "\" => z <= ln" << i << " after 5ns;\n";
   }
   return 0;
}
**/

// Generate randomised test cases for register file in VHDL
/**
int main()
{
   srand(time(NULL));
   for(int i = 0; i < 32; i++)
   {
      int randomNumber = rand();
      std::cout << std::endl;
      std::cout << "-- Load 0x" << std::hex << randomNumber << std::dec << " into register " << i << "\n";
      std::cout << "wait for 10 ns;\n";
      std::bitset<5> destinationRegister(i);
      std::bitset<32> registerValue(randomNumber);
      std::cout << "dest <= \"" << destinationRegister << "\";\n";
      std::cout << "data <= \"" << registerValue << "\";\n";
   }
   return 0;
}
**/

int main()
{
   for(int i = 0; i < 32; i++)
   {
      std::bitset<5> x(i);
      std::cout << "s <= \"" << x << "\";\n";
      std::cout << "wait for 10ns;\n";
   }
   return 0;
}