#ifndef DATABASEUSER_H
#define DATABASEUSER_H

#include <string>
#include <stdexcept>
#include "Dependencies/libbcrypt/include/bcrypt/BCrypt.hpp"

#include "helper-functions.h"
#include "messages.h"

using std::string;

class DatabaseUser{
private:
    string username;
    string password;

protected:

    void setUsername(const string& username);
    void setPassword(const string& password);

public:
    DatabaseUser(const string& username, const string& password);

    string getUsername() const;
    void validatePassword(const string& password) const;
};

#endif