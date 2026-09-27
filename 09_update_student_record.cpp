// 09_update_student_record.cpp - Line-by-line commented version

// Include the required standard library header.
#include <cstdio>
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
// Create an output file stream for writing data.
    std::ofstream temporaryFile("students_temp.txt");

// Check the required condition.
    if (!inputFile || !temporaryFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open file(s).\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    int targetRollNumber;
// Execute the statement shown on the next line.
    double updatedMarks;

// Execute the statement shown on the next line.
    std::cout << "Enter roll number to update: ";
// Execute the statement shown on the next line.
    std::cin >> targetRollNumber;

// Execute the statement shown on the next line.
    std::cout << "Enter updated marks: ";
// Execute the statement shown on the next line.
    std::cin >> updatedMarks;

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

// Check the required condition.
            if (rollNumber == targetRollNumber)
            {
// Execute the statement shown on the next line.
                temporaryFile << rollNumber << '|'
// Execute the statement shown on the next line.
                              << name << '|'
// Execute the statement shown on the next line.
                              << updatedMarks << '\n';
// Execute the statement shown on the next line.
                found = true;
            }
// Execute the statement shown on the next line.
            else
            {
// Execute the statement shown on the next line.
                temporaryFile << line << '\n';
            }
        }
    }

// Close the file after completing file operations.
    inputFile.close();
// Close the file after completing file operations.
    temporaryFile.close();

// Check the required condition.
    if (!found)
    {
// Execute the statement shown on the next line.
        std::remove("students_temp.txt");
// Execute the statement shown on the next line.
        std::cout << "Student record not found. No update performed.\n";
// Return a value to the calling environment.
        return 0;
    }

// Check the required condition.
    if (std::remove("students.txt") != 0)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not remove old students.txt\n";
// Return a value to the calling environment.
        return 1;
    }

// Check the required condition.
    if (std::rename("students_temp.txt", "students.txt") != 0)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not rename temporary file.\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    std::cout << "Student marks updated successfully.\n";
// Return a value to the calling environment.
    return 0;
}
