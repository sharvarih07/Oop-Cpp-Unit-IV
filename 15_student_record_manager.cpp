// 15_student_record_manager.cpp - Line-by-line commented version

// Include the required standard library header.
#include <cstdio>
// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>
// Include the required standard library header.
#include <limits>
// Include the required standard library header.
#include <sstream>
// Include the required standard library header.
#include <string>

// Define a function that performs a specific operation.
void addStudent()
{
// Create an output file stream for writing data.
    std::ofstream outputFile(
// Execute the statement shown on the next line.
        "student_records.txt",
// Execute the statement shown on the next line.
        std::ios::app
// Execute the statement shown on the next line.
    );

// Check the required condition.
    if (!outputFile)
    {
// Execute the statement shown on the next line.
        std::cerr
// Execute the statement shown on the next line.
            << "Error: Could not open student_records.txt\n";
// Execute the statement shown on the next line.
        return;
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
    std::cin.ignore(
// Execute the statement shown on the next line.
        std::numeric_limits<std::streamsize>::max(),
// Execute the statement shown on the next line.
        '\n'
// Execute the statement shown on the next line.
    );
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
    std::cout << "Record added successfully.\n";
}

// Define a function that performs a specific operation.
void displayStudents()
{
// Create an input file stream for reading data.
    std::ifstream inputFile("student_records.txt");

// Check the required condition.
    if (!inputFile)
    {
// Execute the statement shown on the next line.
        std::cout << "No student record file found.\n";
// Execute the statement shown on the next line.
        return;
    }

// Execute the statement shown on the next line.
    std::string line;

// Execute the statement shown on the next line.
    std::cout << "\nRoll No.\tName\t\tMarks\n";
// Execute the statement shown on the next line.
    std::cout << "----------------------------------------\n";

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
            std::cout
// Execute the statement shown on the next line.
                << rollText << "\t\t"
// Execute the statement shown on the next line.
                << name << "\t\t"
// Execute the statement shown on the next line.
                << marksText << '\n';
        }
    }
}

// Define a function that performs a specific operation.
void searchStudent()
{
// Create an input file stream for reading data.
    std::ifstream inputFile("student_records.txt");

// Check the required condition.
    if (!inputFile)
    {
// Execute the statement shown on the next line.
        std::cout << "No student record file found.\n";
// Execute the statement shown on the next line.
        return;
    }

// Execute the statement shown on the next line.
    int targetRoll;

// Execute the statement shown on the next line.
    std::cout << "Enter roll number to search: ";
// Execute the statement shown on the next line.
    std::cin >> targetRoll;

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
// Check the required condition.
            if (std::stoi(rollText) == targetRoll)
            {
// Execute the statement shown on the next line.
                std::cout << "Record Found\n";
// Execute the statement shown on the next line.
                std::cout << "Roll Number: "
// Execute the statement shown on the next line.
                          << rollText << '\n';
// Execute the statement shown on the next line.
                std::cout << "Name: "
// Execute the statement shown on the next line.
                          << name << '\n';
// Execute the statement shown on the next line.
                std::cout << "Marks: "
// Execute the statement shown on the next line.
                          << marksText << '\n';

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
        std::cout << "Student not found.\n";
    }
}

// Define a function that performs a specific operation.
void updateMarks()
{
// Create an input file stream for reading data.
    std::ifstream inputFile("student_records.txt");
// Create an output file stream for writing data.
    std::ofstream temporaryFile(
// Execute the statement shown on the next line.
        "student_records_temp.txt"
// Execute the statement shown on the next line.
    );

// Check the required condition.
    if (!inputFile || !temporaryFile)
    {
// Execute the statement shown on the next line.
        std::cerr
// Execute the statement shown on the next line.
            << "Error: Could not open record file(s).\n";
// Execute the statement shown on the next line.
        return;
    }

// Execute the statement shown on the next line.
    int targetRoll;
// Execute the statement shown on the next line.
    double newMarks;

// Execute the statement shown on the next line.
    std::cout << "Enter roll number to update: ";
// Execute the statement shown on the next line.
    std::cin >> targetRoll;

// Execute the statement shown on the next line.
    std::cout << "Enter new marks: ";
// Execute the statement shown on the next line.
    std::cin >> newMarks;

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
// Check the required condition.
            if (std::stoi(rollText) == targetRoll)
            {
// Execute the statement shown on the next line.
                temporaryFile
// Execute the statement shown on the next line.
                    << rollText << '|'
// Execute the statement shown on the next line.
                    << name << '|'
// Execute the statement shown on the next line.
                    << newMarks << '\n';

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
        std::remove("student_records_temp.txt");
// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "Student not found. No changes made.\n";
// Execute the statement shown on the next line.
        return;
    }

// Check the required condition.
    if (std::remove("student_records.txt") != 0 ||
// Execute the statement shown on the next line.
        std::rename(
// Execute the statement shown on the next line.
            "student_records_temp.txt",
// Execute the statement shown on the next line.
            "student_records.txt"
// Execute the statement shown on the next line.
        ) != 0)
    {
// Execute the statement shown on the next line.
        std::cerr
// Execute the statement shown on the next line.
            << "Error: Could not replace the record file.\n";
// Execute the statement shown on the next line.
        return;
    }

// Execute the statement shown on the next line.
    std::cout
// Execute the statement shown on the next line.
        << "Marks updated successfully.\n";
}

// Program execution starts from the main() function.
int main()
{
// Execute the statement shown on the next line.
    int choice;

// Execute the statement shown on the next line.
    do
    {
// Execute the statement shown on the next line.
        std::cout << "\nStudent Record Manager\n";
// Execute the statement shown on the next line.
        std::cout << "1. Add Student\n";
// Execute the statement shown on the next line.
        std::cout << "2. Display All Students\n";
// Execute the statement shown on the next line.
        std::cout << "3. Search Student\n";
// Execute the statement shown on the next line.
        std::cout << "4. Update Marks\n";
// Execute the statement shown on the next line.
        std::cout << "0. Exit\n";
// Execute the statement shown on the next line.
        std::cout << "Enter choice: ";

// Execute the statement shown on the next line.
        std::cin >> choice;

// Select an operation based on the user's choice.
        switch (choice)
        {
// Handle the selected menu option.
            case 1:
// Execute the statement shown on the next line.
                addStudent();
// Execute the statement shown on the next line.
                break;

// Handle the selected menu option.
            case 2:
// Execute the statement shown on the next line.
                displayStudents();
// Execute the statement shown on the next line.
                break;

// Handle the selected menu option.
            case 3:
// Execute the statement shown on the next line.
                searchStudent();
// Execute the statement shown on the next line.
                break;

// Handle the selected menu option.
            case 4:
// Execute the statement shown on the next line.
                updateMarks();
// Execute the statement shown on the next line.
                break;

// Handle the selected menu option.
            case 0:
// Execute the statement shown on the next line.
                std::cout << "Exiting program.\n";
// Execute the statement shown on the next line.
                break;

// Execute the statement shown on the next line.
            default:
// Execute the statement shown on the next line.
                std::cout
// Execute the statement shown on the next line.
                    << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

// Return a value to the calling environment.
    return 0;
}
