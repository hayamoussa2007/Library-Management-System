Team name: Syntax Squad
Group number: team 17

Team members:
Haya Moussa (24-101252)
Omar Khattab (24-101227)
Zyad Walid (24-101301)
Kareem Salah (24-101283)

User's Manual:

Overview
This Library Management System helps manage books and users in a library. It supports two types of users:

Librarians: Have administrative control to manage books and customers.
Customers: Can search for books, borrow, and return books.
Each user must sign in with a username and password.

1. Login:
Enter your username and password to access the system.
If you are a librarian, you will get access to the librarian view.
If you are a customer, you will get access to the customer view.

Librarian features:
- Add a New Customer: create a new customer account with a unique user ID, username, and password.
- Remove a Customer: delete a customer’s account from the system.
- View Customer Data: see customer details including which books they have borrowed.
- Manage Books: add new books to the library by entering title, author, and category.
- Remove books from the library
- View all books in the library
- Search for Books: search by title, author, or category. Searches are case-insensitive and can find partial matches.
- View Borrowed and Non-Borrowed Books: see lists of all books that are currently borrowed or available.

Customer Features:
- Search for Books: find books by title, author, or category. Search is case-insensitive and supports partial matches.
- View Borrowed Books: see which books they currently have borrowed.
- Borrow Books: borrow a book from the library if it is available. Customers can borrow up to 5 books at a time.
- Return Books: return borrowed books back to the library.

Rules and Notes
- User Authentication: you must log in to access any features.
- Borrow Limit: customers cannot borrow more than 5 books at once.
- Book Categories: books belong to one of these categories: Fiction, Romance, Children, Non-fiction, Horror, History.
- Search Function: searches do not consider uppercase or lowercase letters

Troubleshooting
- Forgot Password: Contact the librarian to reset your password.
- Cannot Borrow More Than 5 Books: Return some books before borrowing more.
- Book Not Found in Search: Make sure you spelled the title/author/category correctly; searches are case-insensitive.