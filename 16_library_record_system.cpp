// 16_library_record_system.cpp - Line-by-line commented version

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
// Include the required standard library header.
#include <utility>

// Define a class to group related data and functions.
class Book
{
// Execute the statement shown on the next line.
private:
// Execute the statement shown on the next line.
    int bookId;
// Execute the statement shown on the next line.
    std::string title;
// Execute the statement shown on the next line.
    std::string author;
// Execute the statement shown on the next line.
    bool issued;

// Execute the statement shown on the next line.
public:
// Execute the statement shown on the next line.
    Book(
// Execute the statement shown on the next line.
        int id,
// Execute the statement shown on the next line.
        std::string bookTitle,
// Execute the statement shown on the next line.
        std::string bookAuthor,
// Execute the statement shown on the next line.
        bool issueStatus = false
// Execute the statement shown on the next line.
    )
// Execute the statement shown on the next line.
        : bookId(id),
// Execute the statement shown on the next line.
          title(std::move(bookTitle)),
// Execute the statement shown on the next line.
          author(std::move(bookAuthor)),
// Execute the statement shown on the next line.
          issued(issueStatus)
    {
    }

// Execute the statement shown on the next line.
    int getBookId() const
    {
// Return a value to the calling environment.
        return bookId;
    }

// Execute the statement shown on the next line.
    std::string toFileRecord() const
    {
// Return a value to the calling environment.
        return std::to_string(bookId)
// Execute the statement shown on the next line.
             + "|"
// Execute the statement shown on the next line.
             + title
// Execute the statement shown on the next line.
             + "|"
// Execute the statement shown on the next line.
             + author
// Execute the statement shown on the next line.
             + "|"
// Execute the statement shown on the next line.
             + (issued ? "1" : "0");
    }

// Define a function that performs a specific operation.
    void display() const
    {
// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "Book ID: "
// Execute the statement shown on the next line.
            << bookId << '\n';

// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "Title: "
// Execute the statement shown on the next line.
            << title << '\n';

// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "Author: "
// Execute the statement shown on the next line.
            << author << '\n';

// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "Status: "
// Execute the statement shown on the next line.
            << (issued ? "Issued" : "Available")
// Execute the statement shown on the next line.
            << '\n';
    }
};

// Define a function that performs a specific operation.
void addBook()
{
// Execute the statement shown on the next line.
    int id;
// Execute the statement shown on the next line.
    std::string title;
// Execute the statement shown on the next line.
    std::string author;

// Execute the statement shown on the next line.
    std::cout << "Enter book ID: ";
// Execute the statement shown on the next line.
    std::cin >> id;

// Execute the statement shown on the next line.
    std::cin.ignore(
// Execute the statement shown on the next line.
        std::numeric_limits<std::streamsize>::max(),
// Execute the statement shown on the next line.
        '\n'
// Execute the statement shown on the next line.
    );

// Execute the statement shown on the next line.
    std::cout << "Enter title: ";
// Read a complete line from the file or input stream.
    std::getline(std::cin, title);

// Execute the statement shown on the next line.
    std::cout << "Enter author: ";
// Read a complete line from the file or input stream.
    std::getline(std::cin, author);

// Execute the statement shown on the next line.
    Book book(id, title, author);

// Create an output file stream for writing data.
    std::ofstream outputFile(
// Execute the statement shown on the next line.
        "library_books.txt",
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
            << "Error: Could not open library_books.txt\n";
// Execute the statement shown on the next line.
        return;
    }

// Execute the statement shown on the next line.
    outputFile
// Execute the statement shown on the next line.
        << book.toFileRecord()
// Execute the statement shown on the next line.
        << '\n';

// Execute the statement shown on the next line.
    std::cout
// Execute the statement shown on the next line.
        << "Book added successfully.\n";
}

// Define a function that performs a specific operation.
void displayBooks()
{
// Create an input file stream for reading data.
    std::ifstream inputFile(
// Execute the statement shown on the next line.
        "library_books.txt"
// Execute the statement shown on the next line.
    );

// Check the required condition.
    if (!inputFile)
    {
// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "No library record file found.\n";
// Execute the statement shown on the next line.
        return;
    }

// Execute the statement shown on the next line.
    std::string line;

// Read a complete line from the file or input stream.
    while (std::getline(inputFile, line))
    {
// Execute the statement shown on the next line.
        std::stringstream record(line);

// Execute the statement shown on the next line.
        std::string idText;
// Execute the statement shown on the next line.
        std::string title;
// Execute the statement shown on the next line.
        std::string author;
// Execute the statement shown on the next line.
        std::string issuedText;

// Read a complete line from the file or input stream.
        if (std::getline(record, idText, '|') &&
// Read a complete line from the file or input stream.
            std::getline(record, title, '|') &&
// Read a complete line from the file or input stream.
            std::getline(record, author, '|') &&
// Read a complete line from the file or input stream.
            std::getline(record, issuedText))
        {
// Execute the statement shown on the next line.
            Book book(
// Execute the statement shown on the next line.
                std::stoi(idText),
// Execute the statement shown on the next line.
                title,
// Execute the statement shown on the next line.
                author,
// Execute the statement shown on the next line.
                issuedText == "1"
// Execute the statement shown on the next line.
            );

// Execute the statement shown on the next line.
            book.display();

// Execute the statement shown on the next line.
            std::cout
// Execute the statement shown on the next line.
                << "-------------------------\n";
        }
    }
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
        std::cout
// Execute the statement shown on the next line.
            << "\nLibrary Record System\n";

// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "1. Add Book\n";

// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "2. Display Books\n";

// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "0. Exit\n";

// Execute the statement shown on the next line.
        std::cout
// Execute the statement shown on the next line.
            << "Enter choice: ";

// Execute the statement shown on the next line.
        std::cin >> choice;

// Select an operation based on the user's choice.
        switch (choice)
        {
// Handle the selected menu option.
            case 1:
// Execute the statement shown on the next line.
                addBook();
// Execute the statement shown on the next line.
                break;

// Handle the selected menu option.
            case 2:
// Execute the statement shown on the next line.
                displayBooks();
// Execute the statement shown on the next line.
                break;

// Handle the selected menu option.
            case 0:
// Execute the statement shown on the next line.
                std::cout
// Execute the statement shown on the next line.
                    << "Exiting program.\n";
// Execute the statement shown on the next line.
                break;

// Execute the statement shown on the next line.
            default:
// Execute the statement shown on the next line.
                std::cout
// Execute the statement shown on the next line.
                    << "Invalid choice.\n";
        }

    } while (choice != 0);

// Return a value to the calling environment.
    return 0;
}
