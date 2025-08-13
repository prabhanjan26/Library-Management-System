#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author)
        : id(id), title(title), author(author), isIssued(false) {}
};

class Library {
private:
    vector<Book> books;

public:
    // Constructor to add initial books
    Library() {
        books.push_back(Book(1, "The Great Gatsby", "F. Scott Fitzgerald"));
        books.push_back(Book(2, "1984", "George Orwell"));
        books.push_back(Book(3, "To Kill a Mockingbird", "Harper Lee"));
        books.push_back(Book(4, "Pride and Prejudice", "Jane Austen"));
        books.push_back(Book(5, "The Catcher in the Rye", "J.D. Salinger"));
    }

    void addBook(int id, string title, string author) {
        // prevent duplicate book IDs
        for (const auto &b : books) {
            if (b.id == id) {
                cout << "Book with ID " << id << " already exists. Cannot add duplicate." << endl;
                return;
            }
        }
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "\n--- Library Books ---\n";
        for (auto &book : books) {
            cout << "ID: " << book.id
                 << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Status: " << (book.isIssued ? "Issued" : "Available") << "\n";
        }
    }

    void issueBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    cout << "Book issued successfully!\n";
                    return;
                } else {
                    cout << "Book is already issued.\n";
                    return;
                }
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void returnBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    cout << "Book returned successfully!\n";
                    return;
                } else {
                    cout << "Book was not issued.\n";
                    return;
                }
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    while (true) {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                cout << "Enter book ID to issue: ";
                cin >> id;
                library.issueBook(id);
                break;

            case 4:
                cout << "Enter book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;

            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
