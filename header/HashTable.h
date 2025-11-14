#pragma once
#include "Vector.h"

template <typename T>
class HashTable{
    private:
        int capacity;
        Vector<T> *table;
    public:
        HashTable(const int x=100);
        ~HashTable();
        int getkey(int )const;
        void hash(const T,const int);
        Vector<T>& operator[](const int );
        HashTable(const HashTable& other);
        HashTable& operator=(const HashTable& other);
        int getcapacity();
};

template <typename T>
HashTable<T>::HashTable(const int capacity):capacity(capacity)
{
    this->table = new Vector<T>[this->capacity];
}

template <typename T>
HashTable<T>::~HashTable()
{
    delete[] table;
}

template <typename T>
void HashTable<T>::hash(const T x,const int key){
    if(key<0 || key >= this->capacity){
        std::cout<<"Out of range\n";
        return;
    }
    (this->table + key)->pb(x);
}

template <typename T>
int HashTable<T>::getkey(int x)const{
    return x % this->capacity;
}

template <typename T>
Vector<T>& HashTable<T>::operator[](const int i){
    if(0<=i && i<this->capacity){
        return *(this->table + i);
    }else{
        std::cout<<"Out of HashTable\n";
        return *(this->table);
    }

}

template <typename T>
int HashTable<T>::getcapacity(){
    return this->capacity;
}

template <typename T>
HashTable<T>::HashTable(const HashTable& other)
    : capacity(other.capacity)
{
    this->table = new Vector<T>[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->table[i] = other.table[i]; 
    }
}

// Copy Assignment Operator
template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable& other) {
    if (this != &other) {
        
        delete[] this->table;

        this->capacity = other.capacity;
        this->table = new Vector<T>[this->capacity];
        
        for (int i = 0; i < this->capacity; i++) {
            this->table[i] = other.table[i];
        }
    }
    return *this;
}
/*
class HashTable_User{
    private:
        int capacity;
        Vector_User *table;
    public:
        HashTable_User(const int x=100);
        ~HashTable_User();
        int getkey(const int )const;
        void hash(User&);
        Vector_User& operator[](const int );
};*/
