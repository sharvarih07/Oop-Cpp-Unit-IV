// 04_copy_text_file.cpp - Line-by-line commented version

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
    std::ifstream sourceFile("message.txt");
// Create an output file stream for writing data.
    std::ofstream destinationFile("message_copy.txt");

// Check the required condition.
    if (!sourceFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open source file.\n";
// Return a value to the calling environment.
        return 1;
    }

// Check the required condition.
    if (!destinationFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not create destination file.\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    std::string line;

// Read a complete line from the file or input stream.
    while (std::getline(sourceFile, line))
    {
// Execute the statement shown on the next line.
        destinationFile << line << '\n';
    }

// Execute the statement shown on the next line.
    std::cout << "File copied successfully to message_copy.txt\n";
// Return a value to the calling environment.
    return 0;
}
