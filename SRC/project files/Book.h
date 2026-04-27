#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED


#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string category;
    bool borrowed;

    bool Validity(const string& c) const;

public:
    Book(string t = "unnamed", string a = "unnamed", string c = "unspecified", bool b = false);

    void setTitle(string t);
    void setAuthor(string a);
    void setCategory(string c);

    string getTitle() const;
    string getAuthor() const;
    string getcategory() const;
    bool getStatus() const;
};

#endif // BOOK_H_INCLUDED
