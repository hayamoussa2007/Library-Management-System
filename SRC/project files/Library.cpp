#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() { count = 0; }

void Library::addBook(Book b)
{
    if (count < 100)
    {
        books[count++] = b;
    } else {
        cout << "Library is full. Cannot add more books.\n";
    }
}

void Library::removeBook(string title)
{
    for (int i = 0; i < count; i++)
    {
        if (books[i].getTitle() == title)
        {
            for (int j = i; j < count - 1; j++)
            {
                books[j] = books[j + 1];
            }
            count--;
            cout << "Book removed.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

string Library::searchByTitle(string title) const
{
    string result = "";
    string searchTerm = toLower(title);
    for (int i = 0; i < count; i++)
    {
        string bookTitle = toLower(books[i].getTitle());
        if (bookTitle.find(searchTerm) != string::npos)
        {
            result += books[i].getTitle() + " by " + books[i].getAuthor() + "\n";
        }
    }
    return result;
}

string Library::getAvailableBooks() const
{
    string result = "";
    for (int i = 0; i < count; i++)
    {
        if (!books[i].getStatus())
        {
            result += books[i].getTitle() + " by " + books[i].getAuthor() + " (Available)\n";
        }
    }
    return result;
}

string Library::getBorrowedBooks() const
{
    string result = "";
    for (int i = 0; i < count; i++)
    {
        if (books[i].getStatus())
        {
            result += books[i].getTitle() + " by " + books[i].getAuthor() + " (Borrowed)\n";
        }
    }
    return result;
}

string Library::toLower(const string& s) const
{
    string result = "";
    for (char ch : s)
    {
        result += tolower(ch);
    }
    return result;
}

bool Library::borrowBook(string title, Book& borrowedBook)
{
    for (int i = 0; i < count; i++)
    {
        if (!books[i].getStatus() && books[i].getTitle() == title)
        {
            books[i] = Book(books[i].getTitle(), books[i].getAuthor(), books[i].getcategory(), true);
            borrowedBook = books[i];
            return true;
        }
    }
    return false;
}

void Library::returnBook(string title)
{
        for (int i = 0; i < count; i++)
        {
            if (books[i].getTitle() == title && books[i].getStatus())
            {
                books[i] = Book(books[i].getTitle(), books[i].getAuthor(), books[i].getcategory(), false);
                return;
            }
        }
    }
