#ifndef LIBRARIAN_H_INCLUDED
#define LIBRARIAN_H_INCLUDED

#include "User.h"
#include "Customer.h"
#include "Library.h"

class Librarian : public User {
private:
    Customer* customers;
    int& customerCount;
    int maxCustomers;

public:
    Librarian(int id, string uname, string pwd, Customer* custArr, int& custCount, int maxCust);

    void addBookToLibrary(Library& lib, Book b);
    void removeBookFromLibrary(Library& lib, string title);
    void viewAllBooks(const Library& lib);
    void searchBookInLibrary(const Library& lib, string title);

    void addCustomer(const Customer& c);
    void removeCustomer(const string& username);
    void viewCustomerBorrowedBooks(const Customer& cust);
    void viewAllCustomers() const;
};


#endif // LIBRARIAN_H_INCLUDED
