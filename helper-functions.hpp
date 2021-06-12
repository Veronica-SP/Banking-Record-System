#ifndef HELPER_FUNTIONS_H
#define HELPER_FUNTIONS_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

#include "messages.h"

using std::string;
using std::vector;

bool isOnlyDigits(const string& str);
bool isEmpty(const string& str);
bool isValidName(const string& name);
string strToLower(const string& str);

//find item in collection by it's unique key

template <typename T>
int getIndexInCollection(vector<T>& collection, const string& key){
    for(int i = 0; i < collection.size(); i++){
        if(key == collection[i].getKey()){
            return i;
        }
    }

    throw std::logic_error(NO_SUCH_ELEMENT_ERR);
}

template <typename T>
T& getItemInCollection(vector<T>& collection, const string& key){
    int index = getIndexInCollection(collection, key);
    return collection[index];
}

template <typename T>
void removeItemFromCollection(vector<T>& collection, const string& key){
    int index = getIndexInCollection(collection, key);
    collection.erase(collection.begin() + index);
}

//collection console output 

template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& collection){
    for(int i = 0; i < collection.size(); i++){
        out << collection[i];
        if(i < collection.size() - 1){
            out << std::endl;
        }
    }

    return out;
}

//collection file input/output

template <typename T>
void serializeColl(std::ofstream& fout, const vector<T>& collection, const string separator){
    fout << collection.size() << separator;
     for(int i = 0; i < collection.size(); i++){
       collection[i].serialize(fout);

       if(i < collection.size() - 1){
           fout << separator;
       }
    }
}
template <typename T>
void deserializeColl(std::istream& fin, vector<T>& collection){
    int size;
    fin >> size;
    for(int i = 0; i < size; i++){
        T newElement;
        newElement.deserialize(fin);
        collection.push_back(newElement);
    }
}

#endif