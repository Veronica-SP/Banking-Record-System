#include "helper-functions.h"

bool isOnlyDigits(string str){
    for(int i = 0; i < str.length(), i++){
        if(str[i] < '0' || str[i] > '9'){
            return false;
        }
    }
    return true;
}

bool isEmpty(string str){
    if(str == ""){
        return true;
    }

    for(int i = 0; i < str.length(); i++){
        if(str[i] != " "){
            return true;
        }
    }

    return false;
}

bool isValidName(string name){

    if(name.length() < 2){
        return false;
    }

    if(name[1] < 'A' || name[1] > 'Z'){
        return false;
    }

    for(int i = 1; i < str.length(), i++){
        if(str[i] < 'a' || str[i] > 'z'){
            return false;
        }
    }
    return true;
}