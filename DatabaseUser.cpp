#include "DatabaseUser.h"

//protected-------------------------------------------

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

//public--------------------------------------------

string DatabaseUser::getUsername() const{
    return username;
}

bool DatabaseUser::validatePassword(const string& password) const{
    return BCrypt::validatePassword(password, this->password);
}

void DatabaseUser::serialize(std::ofstream& fout) const {
    const char* separator = " ";
    fout << username << separator << password;
}

void DatabaseUser::deserialize(std::istream& fin){
    fin >> username >> password;
}

std::ostream& operator<<(std::ostream& out, const DatabaseUser& user){
    out << "Username: " << user.username << std::endl;
    out << "Password: " << user.password;

    return out;
}