// 03_append_data.cpp - Line-by-line commented version

// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>

// Program execution starts from the main() function.
int main()
{
// Create an output file stream for writing data.
    std::ofstream outputFile("message.txt", std::ios::app);

// Check the required condition.
    if (!outputFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open message.txt for appending\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    outputFile << "This line was added using append mode.\n";

// Close the file after completing file operations.
    outputFile.close();

// Execute the statement shown on the next line.
    std::cout << "New line appended successfully.\n";
// Return a value to the calling environment.
    return 0;
}
