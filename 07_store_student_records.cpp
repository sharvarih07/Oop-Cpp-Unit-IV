// 07_store_student_records.cpp - Line-by-line commented version

// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>
// Include the required standard library header.
#include <limits>
// Include the required standard library header.
#include <string>

// Program execution starts from the main() function.
int main()
{
// Create an output file stream for writing data.
    std::ofstream outputFile("students.txt", std::ios::app);

// Check the required condition.
    if (!outputFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open students.txt\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    int rollNumber;
// Execute the statement shown on the next line.
    std::string name;
// Execute the statement shown on the next line.
    double marks;

// Execute the statement shown on the next line.
    std::cout << "Enter roll number: ";
// Execute the statement shown on the next line.
    std::cin >> rollNumber;

// Execute the statement shown on the next line.
    std::cout << "Enter name: ";
// Execute the statement shown on the next line.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// Read a complete line from the file or input stream.
    std::getline(std::cin, name);

// Execute the statement shown on the next line.
    std::cout << "Enter marks: ";
// Execute the statement shown on the next line.
    std::cin >> marks;

// Execute the statement shown on the next line.
    outputFile << rollNumber << '|'
// Execute the statement shown on the next line.
               << name << '|'
// Execute the statement shown on the next line.
               << marks << '\n';

// Execute the statement shown on the next line.
    std::cout << "Student record saved successfully.\n";
// Return a value to the calling environment.
    return 0;
}
