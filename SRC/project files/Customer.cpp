#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() : User(), borrowedCount(0) {}

Customer::Customer(int id, string uname, string pwd)
    : User(id, uname, pwd), borrowedCount(0) {}

bool Customer::borrowBookFromLibrary(Library& lib, string title)
{
    if (borrowedCount >= 5)
    {
        cout << "you reached your borrowing limit." << endl;
        return false;
    }

    Book book;
    if (lib.borrowBook(title, book))
    {
        borrowedBooks[borrowedCount++] = book;
        cout << "Book borrowed: " << title << endl;
        return true;
    } else {
        cout << "Book not available or already borrowed." << endl;
        return false;
    }
}

void Customer::returnBookToLibrary(Library& lib, string title)
{
    for (int i = 0; i < borrowedCount; i++)
    {
        if (borrowedBooks[i].getTitle() == title)
        {
            lib.returnBook(title);
            for (int j = i; j < borrowedCount - 1; j++)
            {
                borrowedBooks[j] = borrowedBooks[j + 1];
            }
            borrowedCount--;
            cout << "Book returned: " << title << endl;
            return;
        }
    }
    cout << "this book was not borrowed." << endl;
}

void Customer::listBorrowedBooks() const
{
    cout << "Borrowed books:" << endl;
    for (int i = 0; i < borrowedCount; i++)
    {
        cout << borrowedBooks[i].getTitle() << " by " << borrowedBooks[i].getAuthor() << endl;
    }
}
