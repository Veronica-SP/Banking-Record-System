#ifndef DATABASEUSER_H
#define DATABASEUSER_H

#include <stdexcept>

#include "./Dependencies/libbcrypt/include/bcrypt/BCrypt.hpp"
#include "helper-functions.hpp"

class DatabaseUser{
private:
    string username;
    string password;

protected:
    void setUsername(const string& username);
    void setPassword(const string& password);

    DatabaseUser() = default;
    DatabaseUser(const string& username, const string& password);

public:
    string getUsername() const;
    bool validatePassword(const string& password) const;

    //file input/output
    void serialize(std::ofstream& fout) const;
    void deserialize(std::istream& fin);

    //console output
    friend std::ostream& operator<<(std::ostream& out, const DatabaseUser& user);
};

#endif