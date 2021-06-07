#ifndef HELPER_FUNTIONS_H
#define HELPER_FUNTIONS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "messages.h"

using std::string;
using std::vector;

bool isOnlyDigits(const string& str);
bool isEmpty(const string& str);
bool isValidName(const string& name);

template <typename T>
int getIndexInCollection(vector<T>& collection, const string& key){
    for(int i = 0; i < collection.size(); i++){
        if(key.compare(collection[i].getKey()) == 0){
            return i;
        }
    }

    throw std::invalid_argument(NO_SUCH_ELEMENT_ERR);
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

template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& collection){
    for(int i = 0; i < collection.size(); i++){
        out << collection[i] << std::endl;
    }

    return out;
}

template <typename T>
void serialize(std::ofstream& fout, const vector<T>& collection, const string separator){
    for(int i = 0; i < collection.size(); i++){
       collection[i].serialize(fout);

       if(i < collection.size() - 1){
           fout << separator;
       }
    }
}
template <typename T>
std::istream& operator>>(std::istream& fin, vector<T>& collection){

    while(fin.peek() != EOF){
        T newElement;
        fin >> newElement;
        collection.push_back(newElement);
    }

    return fin;
}

#endif