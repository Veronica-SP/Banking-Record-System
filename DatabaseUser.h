#ifndef DATABASEUSER_H
#define DATABASEUSER_H

#include <stdexcept>
#include "Dependencies/libbcrypt/include/bcrypt/BCrypt.hpp"
#include <fstream>
#include "helper-functions.hpp"

using std::string;

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
    void validatePassword(const string& password) const;

    friend std::ostream& operator<<(std::ostream& out, const DatabaseUser& user);

    void serialize(std::ofstream& fout) const;
    friend std::istream& operator>>(std::istream& fin, DatabaseUser& user);
};

#endif