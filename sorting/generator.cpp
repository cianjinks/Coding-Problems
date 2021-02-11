#include <iostream>
#include <cstdlib>
#include <fstream>

#define SMALL_DATASET 10
#define MEDIUM_DATASET 100
#define LARGE_DATASET 1000
#define EXTRA_LARGE_DATASET 100000
#define MAX 1000

int main()
{
    std::ofstream file;
    std::cout << "Generating 4 Data Sets: " << std::endl;

    std::cout << "Small of " << SMALL_DATASET << " numbers..." << std::endl;
    file.open("./data/small.txt");
    for(int i = 0; i < SMALL_DATASET; i++)
    {
        file << rand() % MAX << std::endl;
    }
    file.close();

    std::cout << "Medium of " << MEDIUM_DATASET << " numbers..." << std::endl;
    file.open("./data/medium.txt");
    for(int i = 0; i < MEDIUM_DATASET; i++)
    {
        file << rand() % MAX << std::endl;
    }
    file.close();

    std::cout << "Large of " << LARGE_DATASET << " numbers..." << std::endl;
    file.open("./data/large.txt");
    for(int i = 0; i < LARGE_DATASET; i++)
    {
        file << rand() % MAX << std::endl;
    }
    file.close();

    std::cout << "Extra Large of " << EXTRA_LARGE_DATASET << " numbers..." << std::endl;
    file.open("./data/extralarge.txt");
    for(int i = 0; i < EXTRA_LARGE_DATASET; i++)
    {
        file << rand() % MAX << std::endl;
    }
    file.close();

    return 0;
}