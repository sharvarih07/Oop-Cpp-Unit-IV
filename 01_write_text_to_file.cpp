// 01_write_text_to_file.cpp - Line-by-line commented version

// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>

// Program execution starts from the main() function.
int main()
{
// Create an output file stream for writing data.
    std::ofstream outputFile("message.txt");

// Check the required condition.
    if (!outputFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not create message.txt\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    outputFile << "Welcome to C++ File Handling\n";
// Execute the statement shown on the next line.
    outputFile << "This is the first line written to a file.\n";
// Execute the statement shown on the next line.
    outputFile << "Files store data permanently.\n";

// Close the file after completing file operations.
    outputFile.close();

// Execute the statement shown on the next line.
    std::cout << "Data written successfully to message.txt\n";
// Return a value to the calling environment.
    return 0;
}
