// 06_search_word.cpp - Line-by-line commented version

// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>
// Include the required standard library header.
#include <string>

// Program execution starts from the main() function.
int main()
{
// Create an input file stream for reading data.
    std::ifstream inputFile("message.txt");

// Check the required condition.
    if (!inputFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open message.txt\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    std::string searchWord;

// Execute the statement shown on the next line.
    std::cout << "Enter word to search: ";
// Execute the statement shown on the next line.
    std::cin >> searchWord;

// Execute the statement shown on the next line.
    std::string word;
// Execute the statement shown on the next line.
    int count = 0;

// Repeat while the specified condition is true.
    while (inputFile >> word)
    {
// Check the required condition.
        if (word == searchWord)
        {
// Execute the statement shown on the next line.
            ++count;
        }
    }

// Execute the statement shown on the next line.
    std::cout << "The word '" << searchWord
// Execute the statement shown on the next line.
              << "' occurred " << count
// Execute the statement shown on the next line.
              << " time(s).\n";

// Return a value to the calling environment.
    return 0;
}
