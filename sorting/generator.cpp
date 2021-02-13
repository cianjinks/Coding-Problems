#include <iostream>
#include <cstdlib>
#include <fstream>

#define SMALL_DATASET 10
#define MEDIUM_DATASET 100
#define LARGE_DATASET 1000
#define EXTRA_LARGE_DATASET 100000
#define MAX 1000

int GenerateDataFile(const char* location, int size)
{
    std::cout << size << " numbers..." << std::endl;
    std::ofstream file;
    file.open(location);
    if(!file) { return -1;}
    for(int i = 0; i < size; i++)
    {
        file << rand() % MAX << std::endl;
    }
    file.close();
    return 0;
}

int main()
{
    std::cout << "Generating 4 Data Sets: " << std::endl;

    GenerateDataFile("./data/small.txt", SMALL_DATASET);
    GenerateDataFile("./data/medium.txt", MEDIUM_DATASET);
    GenerateDataFile("./data/large.txt", LARGE_DATASET);
    GenerateDataFile("./data/extralarge.txt", EXTRA_LARGE_DATASET);

    return 0;
}