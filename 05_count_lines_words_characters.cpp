// 05_count_lines_words_characters.cpp - Line-by-line commented version

// Include the required standard library header.
#include <cctype>
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
    std::size_t lineCount = 0;
// Execute the statement shown on the next line.
    std::size_t wordCount = 0;
// Execute the statement shown on the next line.
    std::size_t characterCount = 0;
// Execute the statement shown on the next line.
    bool insideWord = false;
// Execute the statement shown on the next line.
    char ch;

// Repeat while the specified condition is true.
    while (inputFile.get(ch))
    {
// Execute the statement shown on the next line.
        ++characterCount;

// Check the required condition.
        if (ch == '\n')
        {
// Execute the statement shown on the next line.
            ++lineCount;
        }

// Check the required condition.
        if (std::isspace(static_cast<unsigned char>(ch)))
        {
// Execute the statement shown on the next line.
            insideWord = false;
        }
// Execute the statement shown on the next line.
        else if (!insideWord)
        {
// Execute the statement shown on the next line.
            ++wordCount;
// Execute the statement shown on the next line.
            insideWord = true;
        }
    }

// Check the required condition.
    if (characterCount > 0)
    {
// Execute the statement shown on the next line.
        inputFile.clear();
// Move the input/read file pointer.
        inputFile.seekg(-1, std::ios::end);

// Execute the statement shown on the next line.
        char lastCharacter;
// Execute the statement shown on the next line.
        inputFile.get(lastCharacter);

// Check the required condition.
        if (lastCharacter != '\n')
        {
// Execute the statement shown on the next line.
            ++lineCount;
        }
    }

// Execute the statement shown on the next line.
    std::cout << "Lines: " << lineCount << '\n';
// Execute the statement shown on the next line.
    std::cout << "Words: " << wordCount << '\n';
// Execute the statement shown on the next line.
    std::cout << "Characters: " << characterCount << '\n';

// Return a value to the calling environment.
    return 0;
}
