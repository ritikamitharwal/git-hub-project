#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author) : id(id), title(title), author(author), isIssued(false) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
    }

    void issueBook(int id) {
        for (auto &book : books) {
            if (book.id == id && !book.isIssued) {
                book.isIssued = true;
                cout << "Book issued successfully.\n";
                return;
            }
        }
        cout << "Book not found or already issued.\n";
    }

    void returnBook(int id) {
        for (auto &book : books) {
            if (book.id == id && book.isIssued) {
                book.isIssued = false;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found or wasn't issued.\n";
    }

    void searchBookByTitle(string title) {
        for (const auto &book : books) {
            if (book.title == title) {
                cout << "Book ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
                     << (book.isIssued ? " (Issued)\n" : " (Available)\n");
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void searchBookByAuthor(string author) {
        for (const auto &book : books) {
            if (book.author == author) {
                cout << "Book ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
                     << (book.isIssued ? " (Issued)\n" : " (Available)\n");
            }
        }
    }

    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        for (const auto &book : books) {
            cout << "Book ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
                 << (book.isIssued ? " (Issued)\n" : " (Available)\n");
        }
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search Book by Title\n";
        cout << "5. Search Book by Author\n";
        cout << "6. Display All Books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();  // to ignore the newline character after the integer input
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;

        case 2:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            library.issueBook(id);
            break;

        case 3:
            cout << "Enter Book ID to return: ";
            cin >> id;
            library.returnBook(id);
            break;

        case 4:
            cout << "Enter Book Title to search: ";
            cin.ignore();
            getline(cin, title);
            library.searchBookByTitle(title);
            break;

        case 5:
            cout << "Enter Book Author to search: ";
            cin.ignore();
            getline(cin, author);
            library.searchBookByAuthor(author);
            break;

        case 6:
            library.displayAllBooks();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
