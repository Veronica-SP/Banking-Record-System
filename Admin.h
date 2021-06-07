#ifndef ADMIN_H
#define ADMIN_H

#include "DatabaseUser.h"

class Admin : public DatabaseUser{
public:
    Admin() = default;
    Admin(const string& username, const string& password);
};


#endif