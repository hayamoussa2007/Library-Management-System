#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED


#include <string>
using namespace std;

class User {
protected:
    int userID;
    string username;
    string password;

public:
    User();
    User(int id, string uname, string pwd);
    int getUserID() const;
    string getUsername() const;
    bool authenticate(const string& uname, const string& pwd) const;
};



#endif // USER_H_INCLUDED
