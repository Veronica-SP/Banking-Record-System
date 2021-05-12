#include "DatabaseUser.h"

void DatabaseUser::setUsername(const string& username){
    if(isEmpty(username)){
        throw std::invalid_argument(USERNAME_EMPTY_ERR);
    }

    if(username.find(" ") !=  string::npos){
        throw std::invalid_argument(USERNAME_CONTAINS_SPACE__ERR);
    }

    this->username = username;
}

void DatabaseUser::setPassword(const string& password){
    if(isEmpty(password)){
        throw std::invalid_argument(PASS_EMPTY_ERR);
    }

    if(password.find(" ") !=  string::npos){
        throw std::invalid_argument(PASS_CONTAINS_SPACE__ERR);
    }

    this->password  = BCrypt::generateHash(password);
}

DatabaseUser::DatabaseUser(const string& username, const string& password){
    setUsername(username);
    setPassword(password);
}

void DatabaseUser::validatePassword(string password) const{
    bool passIsValid = BCrypt::validatePassword(password, this->password);

    if(!passIsValid){
        throw std::logic_error(PASS_WRONG_ERR);
    }
}