#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(string t, string a, string c, bool b) {
    title = t;
    author = a;
    category = c;
    borrowed = b;
}

bool Book::Validity(const string &c) const {
    const string validCategories[12] = {
        "Fiction", "Romance", "Children", "Non-fiction", "Horror", "History", "fiction", "romance", "children", "non-fiction", "horror", "history"
    };

    for (int i = 0; i < 12; i++) {
        if (c == validCategories[i]) {
            return true;
        }
    }
    return false;
}

void Book::setTitle(string t) {
    title = t;
}

void Book::setAuthor(string a) {
    author = a;
}

void Book::setCategory(string c) {
    if (Validity(c)) {
        category = c;
    } else {
        cout << "Invalid category" << endl;
        category = "unspecified";
    }
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getcategory() const {
    return category;
}
bool Book::getStatus() const {
	return borrowed;
}
