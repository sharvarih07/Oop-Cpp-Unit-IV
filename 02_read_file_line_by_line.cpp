// 02_read_file_line_by_line.cpp - Line-by-line commented version

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
    std::string line;

// Execute the statement shown on the next line.
    std::cout << "File Content:\n";

// Read a complete line from the file or input stream.
    while (std::getline(inputFile, line))
    {
// Execute the statement shown on the next line.
        std::cout << line << '\n';
    }

// Close the file after completing file operations.
    inputFile.close();

// Return a value to the calling environment.
    return 0;
}
