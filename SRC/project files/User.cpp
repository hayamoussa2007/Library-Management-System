#include "User.h"

User::User() : userID(0), username(""), password("") {}
User::User(int id, string uname, string pwd) : userID(id), username(uname), password(pwd) {}

int User::getUserID() const
{
    return userID;
}

string User::getUsername() const
{
     return username;
}

bool User::authenticate(const string& uname, const string& pwd) const
{
    return (username == uname && password == pwd);
}

