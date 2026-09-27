// 08_read_search_student_records.cpp - Line-by-line commented version

// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>
// Include the required standard library header.
#include <sstream>
// Include the required standard library header.
#include <string>

// Program execution starts from the main() function.
int main()
{
// Create an input file stream for reading data.
    std::ifstream inputFile("students.txt");

// Check the required condition.
    if (!inputFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open students.txt\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    int targetRollNumber;

// Execute the statement shown on the next line.
    std::cout << "Enter roll number to search: ";
// Execute the statement shown on the next line.
    std::cin >> targetRollNumber;

// Execute the statement shown on the next line.
    std::string line;
// Execute the statement shown on the next line.
    bool found = false;

// Read a complete line from the file or input stream.
    while (std::getline(inputFile, line))
    {
// Execute the statement shown on the next line.
        std::stringstream record(line);

// Execute the statement shown on the next line.
        std::string rollText;
// Execute the statement shown on the next line.
        std::string name;
// Execute the statement shown on the next line.
        std::string marksText;

// Read a complete line from the file or input stream.
        if (std::getline(record, rollText, '|') &&
// Read a complete line from the file or input stream.
            std::getline(record, name, '|') &&
// Read a complete line from the file or input stream.
            std::getline(record, marksText))
        {
// Execute the statement shown on the next line.
            int rollNumber = std::stoi(rollText);
// Execute the statement shown on the next line.
            double marks = std::stod(marksText);

// Check the required condition.
            if (rollNumber == targetRollNumber)
            {
// Execute the statement shown on the next line.
                std::cout << "Record Found\n";
// Execute the statement shown on the next line.
                std::cout << "Roll Number: " << rollNumber << '\n';
// Execute the statement shown on the next line.
                std::cout << "Name: " << name << '\n';
// Execute the statement shown on the next line.
                std::cout << "Marks: " << marks << '\n';

// Execute the statement shown on the next line.
                found = true;
// Execute the statement shown on the next line.
                break;
            }
        }
    }

// Check the required condition.
    if (!found)
    {
// Execute the statement shown on the next line.
        std::cout << "Student record not found.\n";
    }

// Return a value to the calling environment.
    return 0;
}
