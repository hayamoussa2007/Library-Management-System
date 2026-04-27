#include "Librarian.h"
#include <iostream>
using namespace std;

Librarian::Librarian(int id, string uname, string pwd, Customer* custArr, int& custCount, int maxCust)
    : User(id, uname, pwd), customers(custArr), customerCount(custCount), maxCustomers(maxCust) {}

void Librarian::addBookToLibrary(Library& lib, Book b)
{
    lib.addBook(b);
}

void Librarian::removeBookFromLibrary(Library& lib, string title)
{
    lib.removeBook(title);
}

void Librarian::viewAllBooks(const Library& lib)
{
    cout << lib.getAvailableBooks();
    cout << lib.getBorrowedBooks();
}

void Librarian::searchBookInLibrary(const Library& lib, string title)
{
    cout << lib.searchByTitle(title);
}

void Librarian::addCustomer(const Customer& c)
{
    if (customerCount < maxCustomers)
    {
        customers[customerCount++] = c;
        cout << "Customer added: " << c.getUsername() << endl;
    } else {
        cout << "Maximum number of customers reached." << endl;
    }
}

void Librarian::removeCustomer(const string& username)
{
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getUsername() == username)
        {
            for (int j = i; j < customerCount - 1; j++)
            {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            cout << "Customer removed: " << username << endl;
            return;
        }
    }
    cout << "Customer not found: " << username << endl;
}

void Librarian::viewCustomerBorrowedBooks(const Customer& cust)
{
    cust.listBorrowedBooks();
}

void Librarian::viewAllCustomers() const
{
    cout << "Customers in system:" << endl;
    for (int i = 0; i < customerCount; i++)
    {
        cout << customers[i].getUsername() << " (ID: " << customers[i].getUserID() << ")" << endl;
        customers[i].listBorrowedBooks();
    }
}
