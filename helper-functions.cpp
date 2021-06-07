#include "helper-functions.hpp"

bool isOnlyDigits(const string& str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] < '0' || str[i] > '9'){
            return false;
        }
    }
    return true;
}

bool isEmpty(const string& str){
    if(str == ""){
        return true;
    }

    for(int i = 0; i < str.length(); i++){
        if(str[i] != ' '){
            return false;
        }
    }

    return true;
}

bool isValidName(const string& name){

    if(name.length() < 2){
        return false;
    }

    if(name[0] < 'A' || name[0] > 'Z'){
        return false;
    }

    for(int i = 1; i < name.length(); i++){

        if(name[i] < 'a' || name[i] > 'z'){
            return false;
        }
    }
    return true;
    
}