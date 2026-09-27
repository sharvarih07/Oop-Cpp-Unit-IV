// 12_random_access_binary_file.cpp - Line-by-line commented version

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

// Define a function that performs a specific operation.
void addRecord(
// Create an output file stream for writing data.
    std::ofstream& file,
// Execute the statement shown on the next line.
    int rollNumber,
// Execute the statement shown on the next line.
    const char* name,
// Execute the statement shown on the next line.
    float marks
// Execute the statement shown on the next line.
)
{
// Execute the statement shown on the next line.
    StudentRecord student{};

// Execute the statement shown on the next line.
    student.rollNumber = rollNumber;

// Execute the statement shown on the next line.
    std::strncpy(
// Execute the statement shown on the next line.
        student.name,
// Execute the statement shown on the next line.
        name,
// Execute the statement shown on the next line.
        sizeof(student.name) - 1
// Execute the statement shown on the next line.
    );

// Execute the statement shown on the next line.
    student.marks = marks;

// Write binary data from memory into the file.
    file.write(
// Execute the statement shown on the next line.
        reinterpret_cast<const char*>(&student),
// Execute the statement shown on the next line.
        sizeof(student)
// Execute the statement shown on the next line.
    );
}

// Program execution starts from the main() function.
int main()
{
    {
// Create an output file stream for writing data.
        std::ofstream outputFile(
// Execute the statement shown on the next line.
            "records.dat",
// Execute the statement shown on the next line.
            std::ios::binary | std::ios::trunc
// Execute the statement shown on the next line.
        );

// Check the required condition.
        if (!outputFile)
        {
// Execute the statement shown on the next line.
            std::cerr << "Error: Could not create records.dat\n";
// Return a value to the calling environment.
            return 1;
        }

// Execute the statement shown on the next line.
        addRecord(outputFile, 101, "Amit", 85.5F);
// Execute the statement shown on the next line.
        addRecord(outputFile, 102, "Neha", 91.0F);
// Execute the statement shown on the next line.
        addRecord(outputFile, 103, "Ravi", 78.0F);
    }

// Create an input file stream for reading data.
    std::ifstream inputFile(
// Execute the statement shown on the next line.
        "records.dat",
// Execute the statement shown on the next line.
        std::ios::binary
// Execute the statement shown on the next line.
    );

// Check the required condition.
    if (!inputFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not open records.dat\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    int recordNumber;

// Execute the statement shown on the next line.
    std::cout << "Enter record number to read (1 to 3): ";
// Execute the statement shown on the next line.
    std::cin >> recordNumber;

// Check the required condition.
    if (recordNumber < 1 || recordNumber > 3)
    {
// Execute the statement shown on the next line.
        std::cerr << "Invalid record number.\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    const std::streamoff offset =
// Execute the statement shown on the next line.
        static_cast<std::streamoff>(recordNumber - 1) *
// Execute the statement shown on the next line.
        static_cast<std::streamoff>(sizeof(StudentRecord));

// Move the input/read file pointer.
    inputFile.seekg(offset, std::ios::beg);

// Execute the statement shown on the next line.
    StudentRecord selectedStudent{};

// Read binary data from the file into memory.
    inputFile.read(
// Execute the statement shown on the next line.
        reinterpret_cast<char*>(&selectedStudent),
// Execute the statement shown on the next line.
        sizeof(selectedStudent)
// Execute the statement shown on the next line.
    );

// Check the required condition.
    if (!inputFile)
    {
// Execute the statement shown on the next line.
        std::cerr << "Error: Could not read selected record.\n";
// Return a value to the calling environment.
        return 1;
    }

// Execute the statement shown on the next line.
    std::cout << "Roll Number: "
// Execute the statement shown on the next line.
              << selectedStudent.rollNumber << '\n';

// Execute the statement shown on the next line.
    std::cout << "Name: "
// Execute the statement shown on the next line.
              << selectedStudent.name << '\n';

// Execute the statement shown on the next line.
    std::cout << "Marks: "
// Execute the statement shown on the next line.
              << selectedStudent.marks << '\n';

// Return a value to the calling environment.
    return 0;
}
