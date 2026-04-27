#include <iostream>
#include <string>
#include "Library.h"
#include "Book.h"
#include "User.h"
#include "Customer.h"
#include "Librarian.h"

using namespace std;

// Initializing the system with a default librarian account
Librarian setupLibrarian(Customer* customers, int& customerCount, int maxCustomers) {
    return Librarian(1, "admin", "admin123", customers, customerCount, maxCustomers);
}

// Display menu and actions available to a librarian after logging in
void librarianView(Librarian& librarian, Library& library) {
    int choice;
    do {
        cout << "\n--- Librarian Menu ---\n"
             << "1. Add Book\n2. Remove Book\n3. View All Books\n4. Search Book\n"
             << "5. Add Customer\n6. Remove Customer\n7. View All Customers\n8. Logout\n"
             << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        string title, author, category, username, password;
        switch (choice) {
            case 1:
                cout << "Enter title: "; getline(cin, title);
                cout << "Enter author: "; getline(cin, author);
                cout << "Enter category: "; getline(cin, category);
                librarian.addBookToLibrary(library, Book(title, author, category));
                break;
            case 2:
                cout << "Enter title to remove: "; getline(cin, title);
                librarian.removeBookFromLibrary(library, title);
                break;
            case 3:
                librarian.viewAllBooks(library);
                break;
            case 4:
                cout << "Enter search keyword: "; getline(cin, title);
                librarian.searchBookInLibrary(library, title);
                break;
            case 5:
                cout << "Enter new customer username: "; getline(cin, username);
                cout << "Enter password: "; getline(cin, password);
                librarian.addCustomer(Customer(100 + rand() % 900, username, password));
                break;
            case 6:
                cout << "Enter username to remove: "; getline(cin, username);
                librarian.removeCustomer(username);
                break;
            case 7:
                librarian.viewAllCustomers();
                break;
            case 8:
                return; // log out
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (true);
}

// Authentication of customer login
Customer* loginCustomer(Customer* customers, int count) {
    string uname, pwd;
    cout << "Username: "; cin >> uname;
    cout << "Password: "; cin >> pwd;

    for (int i = 0; i < count; i++) {
        if (customers[i].authenticate(uname, pwd)) {
            return &customers[i];
        }
    }
    cout << "Authentication failed.\n";
    return nullptr;
}

// Display menu and actions available to a customer after logging in
void customerView(Customer* cust, Library& library) {
    int choice;
    do {
        cout << "\n--- Customer Menu ---\n"
             << "1. View Available Books\n2. Search Book\n3. Borrow Book\n4. Return Book\n"
             << "5. My Borrowed Books\n6. Logout\n"
             << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        string title;
        switch (choice) {
            case 1:
                cout << library.getAvailableBooks();
                break;
            case 2:
                cout << "Enter search keyword: "; getline(cin, title);
                cout << library.searchByTitle(title);
                break;
            case 3:
                cout << "Enter title to borrow: "; getline(cin, title);
                if (cust->borrowBookFromLibrary(library,title)) {
                    cout << "Book borrowed: " << title << endl;
                }
                break;
            case 4:
                cout << "Enter title to return: "; getline(cin, title);
                cust->returnBookToLibrary(library,title);
                break;
            case 5:
                cust->listBorrowedBooks();
                break;
            case 6:
                return; // log out
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (true);
}



int main() {
    Library library;                        // creating library
    const int maxCustomers = 50;           // maximum number of customers allowed
    Customer customers[maxCustomers];      // array that carries all customer information
    int customerCount = 0;                 // number of customers in the system

    Librarian librarian = setupLibrarian(customers, customerCount, maxCustomers); // Default librarian account that manages the system

    while (true) {
        cout << "\n=== Library Management System ===\n"
             << "1. Librarian Login\n2. Customer Login\n3. Exit\n"
             << "Select role: ";

        int role;
        cin >> role;
        cin.ignore();

        if (role == 1) {
            // Librarian login
            string uname, pwd;
            cout << "Librarian Username: "; cin >> uname;
            cout << "Password: "; cin >> pwd;
            if (librarian.authenticate(uname, pwd)) {
                librarianView(librarian, library);
            } else {
                cout << "Invalid librarian credentials.\n";
            }
        } else if (role == 2) {
            // Customer login
            Customer* cust = loginCustomer(customers, customerCount);
            if (cust) customerView(cust, library);
        } else if (role == 3) {
            // Exit system
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid selection.\n";
        }
    }

    return 0;
}
