#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "User.h"
#include "Book.h"
#include "Library.h"

class Customer : public User {
private:
    Book borrowedBooks[5];
    int borrowedCount;

public:
    Customer();
    Customer(int id, string uname, string pwd);

    bool borrowBookFromLibrary(Library& lib, string title);
    void returnBookToLibrary(Library& lib, string title);
    void listBorrowedBooks() const;
};

#endif // CUSTOMER_H_INCLUDED
