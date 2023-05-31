#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
   
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    std::vector<std::string> strings;
    std::string str;
    while (std::getline(file, str)) {
        strings.push_back(str);
    }

    file.close();

    std::srand(std::time(nullptr));

    std::string random_string = strings[std::rand() % strings.size()];

    std::cout << "Randomly chosen string: " << random_string << std::endl;

    return 0;
}
//comment to add other keyboards to this list
