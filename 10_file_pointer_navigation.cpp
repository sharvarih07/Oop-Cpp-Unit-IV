// 10_file_pointer_navigation.cpp - Line-by-line commented version

// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>

// Program execution starts from the main() function.
int main()
{
// Create a file stream for both reading and writing.
    std::fstream file(
// Execute the statement shown on the next line.
        "navigation.txt",
// Execute the statement shown on the next line.
        std::ios::in | std::ios::out | std::ios::trunc
// Execute the statement shown on the next line.
    );

// Check the required condition.
    if (!file)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open navigation.txt\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    file << "ABCDE";

// Execute the statement shown on the next line.
    std::cout << "Output position after writing: "
// Get the current output/write file position.
              << file.tellp() << '\n';

// Execute the statement shown on the next line.
    file.flush();

// Move the input/read file pointer.
    file.seekg(0, std::ios::beg);

// Execute the statement shown on the next line.
    char firstCharacter;
// Execute the statement shown on the next line.
    file.get(firstCharacter);

// Execute the statement shown on the next line.
    std::cout << "First character: "
// Execute the statement shown on the next line.
              << firstCharacter << '\n';

// Execute the statement shown on the next line.
    std::cout << "Input position after reading one character: "
// Get the current input/read file position.
              << file.tellg() << '\n';

// Move the input/read file pointer.
    file.seekg(2, std::ios::beg);

// Execute the statement shown on the next line.
    char thirdCharacter;
// Execute the statement shown on the next line.
    file.get(thirdCharacter);

// Execute the statement shown on the next line.
    std::cout << "Character at position 2: "
// Execute the statement shown on the next line.
              << thirdCharacter << '\n';

// Move the output/write file pointer.
    file.seekp(5, std::ios::beg);
// Execute the statement shown on the next line.
    file << "F";

// Close the file after completing file operations.
    file.close();

// Execute the statement shown on the next line.
    std::cout << "Navigation completed. Check navigation.txt\n";
// Return a value to the calling environment.
    return 0;
}
