#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <string>
#include "Book.h"
using namespace std;

class Library {
private:
    Book books[100];
    int count;

    string toLower(const string& s) const;

public:
    Library();

    void addBook(Book b);
    void removeBook(string title);
    string searchByTitle(string title) const;
    string getAvailableBooks() const;
    string getBorrowedBooks() const;
    bool borrowBook(string title, Book& borrowedBook);
    void returnBook(string title);
};


#endif // LIBRARY_H_INCLUDED
