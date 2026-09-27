// 14_file_statistics.cpp - Line-by-line commented version

// Include the required standard library header.
#include <cctype>
// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>
// Include the required standard library header.
#include <string>

// Execute the statement shown on the next line.
bool isVowel(char ch)
{
// Execute the statement shown on the next line.
    ch = static_cast<char>(
// Execute the statement shown on the next line.
        std::tolower(static_cast<unsigned char>(ch))
// Execute the statement shown on the next line.
    );

// Return a value to the calling environment.
    return ch == 'a' ||
// Execute the statement shown on the next line.
           ch == 'e' ||
// Execute the statement shown on the next line.
           ch == 'i' ||
// Execute the statement shown on the next line.
           ch == 'o' ||
// Execute the statement shown on the next line.
           ch == 'u';
}

// Program execution starts from the main() function.
int main()
{
// Execute the statement shown on the next line.
    std::string fileName;

// Execute the statement shown on the next line.
    std::cout << "Enter file name: ";
// Read a complete line from the file or input stream.
    std::getline(std::cin, fileName);

// Create an input file stream for reading data.
    std::ifstream inputFile(fileName);

// Check the required condition.
    if (!inputFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open "
// Execute the statement shown on the next line.
                  << fileName << '\n';
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    std::size_t lines = 0;
// Execute the statement shown on the next line.
    std::size_t words = 0;
// Execute the statement shown on the next line.
    std::size_t characters = 0;
// Execute the statement shown on the next line.
    std::size_t vowels = 0;
// Execute the statement shown on the next line.
    std::size_t digits = 0;
// Execute the statement shown on the next line.
    std::size_t spaces = 0;

// Execute the statement shown on the next line.
    bool insideWord = false;
// Execute the statement shown on the next line.
    char ch;

// Repeat while the specified condition is true.
    while (inputFile.get(ch))
    {
// Execute the statement shown on the next line.
        ++characters;

// Check the required condition.
        if (ch == '\n')
        {
// Execute the statement shown on the next line.
            ++lines;
        }

// Check the required condition.
        if (std::isspace(
// Execute the statement shown on the next line.
                static_cast<unsigned char>(ch)))
        {
// Check the required condition.
            if (ch == ' ')
            {
// Execute the statement shown on the next line.
                ++spaces;
            }

// Execute the statement shown on the next line.
            insideWord = false;
        }
// Execute the statement shown on the next line.
        else if (!insideWord)
        {
// Execute the statement shown on the next line.
            ++words;
// Execute the statement shown on the next line.
            insideWord = true;
        }

// Check the required condition.
        if (std::isalpha(
// Execute the statement shown on the next line.
                static_cast<unsigned char>(ch))
// Execute the statement shown on the next line.
            && isVowel(ch))
        {
// Execute the statement shown on the next line.
            ++vowels;
        }

// Check the required condition.
        if (std::isdigit(
// Execute the statement shown on the next line.
                static_cast<unsigned char>(ch)))
        {
// Execute the statement shown on the next line.
            ++digits;
        }
    }

// Check the required condition.
    if (characters > 0)
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
            ++lines;
        }
    }

// Execute the statement shown on the next line.
    std::cout << "\nFile Statistics\n";
// Execute the statement shown on the next line.
    std::cout << "Lines: " << lines << '\n';
// Execute the statement shown on the next line.
    std::cout << "Words: " << words << '\n';
// Execute the statement shown on the next line.
    std::cout << "Characters: " << characters << '\n';
// Execute the statement shown on the next line.
    std::cout << "Vowels: " << vowels << '\n';
// Execute the statement shown on the next line.
    std::cout << "Digits: " << digits << '\n';
// Execute the statement shown on the next line.
    std::cout << "Spaces: " << spaces << '\n';

// Return a value to the calling environment.
    return 0;
}
