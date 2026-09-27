// 13_file_error_handling.cpp - Line-by-line commented version

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
    std::ifstream inputFile("missing_file.txt");

// Check the required condition.
    if (!inputFile.is_open())
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: File could not be opened.\n";
// Execute the statement shown on the next line.
        std::cerr
// Execute the statement shown on the next line.
            << "Check whether missing_file.txt exists "
// Execute the statement shown on the next line.
            << "in the current folder.\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    std::string line;

// Read a complete line from the file or input stream.
    while (std::getline(inputFile, line))
    {
// Execute the statement shown on the next line.
        std::cout << line << '\n';
    }

// Check the required condition.
    if (inputFile.eof())
    {
// Execute the statement shown on the next line.
        std::cout << "End of file reached normally.\n";
    }
// Execute the statement shown on the next line.
    else if (inputFile.bad())
    {
// Execute the statement shown on the next line.
        std::cerr << "A serious file I/O error occurred.\n";
    }
// Execute the statement shown on the next line.
    else if (inputFile.fail())
    {
// Execute the statement shown on the next line.
        std::cerr << "A logical file read error occurred.\n";
    }

// Return a value to the calling environment.
    return 0;
}
