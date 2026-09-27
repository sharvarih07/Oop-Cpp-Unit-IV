// 11_binary_file_read_write.cpp - Line-by-line commented version

// Include the required standard library header.
#include <cstring>
// Include the required standard library header.
#include <fstream>
// Include the required standard library header.
#include <iostream>

// Define a structure to group related record fields.
struct StudentRecord
{
// Execute the statement shown on the next line.
    int rollNumber;
// Execute the statement shown on the next line.
    char name[30];
// Execute the statement shown on the next line.
    float marks;
};

// Program execution starts from the main() function.
int main()
{
// Execute the statement shown on the next line.
    StudentRecord student{};

// Execute the statement shown on the next line.
    student.rollNumber = 101;

// Execute the statement shown on the next line.
    std::strncpy(
// Execute the statement shown on the next line.
        student.name,
// Execute the statement shown on the next line.
        "Amit Patil",
// Execute the statement shown on the next line.
        sizeof(student.name) - 1
// Execute the statement shown on the next line.
    );

// Execute the statement shown on the next line.
    student.marks = 85.5F;

    {
// Create an output file stream for writing data.
        std::ofstream outputFile(
// Execute the statement shown on the next line.
            "students.dat",
// Execute the statement shown on the next line.
            std::ios::binary
// Execute the statement shown on the next line.
        );

// Check the required condition.
        if (!outputFile)
        {
// Execute the statement shown on the next line.
            std::cerr << "Error: Could not create students.dat\n";
// Return a value to the calling environment.
            return 1;
        }

// Write binary data from memory into the file.
        outputFile.write(
// Execute the statement shown on the next line.
            reinterpret_cast<const char*>(&student),
// Execute the statement shown on the next line.
            sizeof(student)
// Execute the statement shown on the next line.
        );
    }

// Execute the statement shown on the next line.
    StudentRecord readStudent{};

    {
// Create an input file stream for reading data.
        std::ifstream inputFile(
// Execute the statement shown on the next line.
            "students.dat",
// Execute the statement shown on the next line.
            std::ios::binary
// Execute the statement shown on the next line.
        );

// Check the required condition.
        if (!inputFile)
        {
// Execute the statement shown on the next line.
            std::cerr << "Error: Could not open students.dat\n";
// Return a value to the calling environment.
            return 1;
        }

// Read binary data from the file into memory.
        inputFile.read(
// Execute the statement shown on the next line.
            reinterpret_cast<char*>(&readStudent),
// Execute the statement shown on the next line.
            sizeof(readStudent)
// Execute the statement shown on the next line.
        );

// Check the required condition.
        if (!inputFile)
        {
// Execute the statement shown on the next line.
            std::cerr << "Error: Could not read record from students.dat\n";
// Return a value to the calling environment.
            return 1;
        }
    }

// Execute the statement shown on the next line.
    std::cout << "Roll Number: "
// Execute the statement shown on the next line.
              << readStudent.rollNumber << '\n';

// Execute the statement shown on the next line.
    std::cout << "Name: "
// Execute the statement shown on the next line.
              << readStudent.name << '\n';

// Execute the statement shown on the next line.
    std::cout << "Marks: "
// Execute the statement shown on the next line.
              << readStudent.marks << '\n';

// Return a value to the calling environment.
    return 0;
}
