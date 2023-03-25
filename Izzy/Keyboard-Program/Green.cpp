#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
    // Open the file
    std::ifstream file("input.txt");

    // Check if the file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    // Read the contents of the file into a vector of strings
    std::vector<std::string> strings;
    std::string str;
    while (std::getline(file, str)) {
        strings.push_back(str);
    }

    // Close the file
    file.close();

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Choose a random string from the vector
    std::string random_string = strings[std::rand() % strings.size()];

    // Print the chosen string
    std::cout << "Randomly chosen string: " << random_string << std::endl;

    return 0;
}
