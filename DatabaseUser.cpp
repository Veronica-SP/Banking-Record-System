#include "DatabaseUser.h"

//protected

void DatabaseUser::setUsername(const string& username){
    if(isEmpty(username)){
        throw std::invalid_argument(USERNAME_EMPTY_ERR);
    }

    if(username.find(" ") != string::npos){
        throw std::invalid_argument(USERNAME_CONTAINS_SPACE_ERR);
    }

    this->username = username;
}

void DatabaseUser::setPassword(const string& password){
    if(isEmpty(password)){
        throw std::invalid_argument(PASS_EMPTY_ERR);
    }

    if(password.find(" ") !=  string::npos){
        throw std::invalid_argument(PASS_CONTAINS_SPACE_ERR);
    }

    this->password  = BCrypt::generateHash(password);
}

DatabaseUser::DatabaseUser(const string& username, const string& password){
    setUsername(username);
    setPassword(password);
}

//public

string DatabaseUser::getUsername() const{
    return username;
}

void DatabaseUser::validatePassword(const string& password) const{
    bool passIsValid = BCrypt::validatePassword(password, this->password);

    if(!passIsValid){
        throw std::logic_error(PASS_WRONG_ERR);
    }
}

std::ostream& operator<<(std::ostream& out, const DatabaseUser& user){
    out << "Username: " << user.username << std::endl;
    out << "Password: " << user.password;

    return out;
}

void DatabaseUser::serialize(std::ofstream& fout) const {
    const string separator = " ";

    fout << username << separator << password;
}

std::istream& operator>>(std::istream& fin, DatabaseUser& user){

    fin >> user.username >> user.password;

    return fin;
}