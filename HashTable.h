#pragma once
#include "Vector.h"
#include"Vector_User.h"

template <typename T>
class HashTable{
    private:
        int capacity;
        Vector<T> *table;
    public:
        HashTable(const int x=100);
        ~HashTable();
        int getkey(int )const;
        void hash(const T);
        Vector<T>& operator[](const int );
        int getcapacity();
};

template <typename T>
HashTable<T>::HashTable(const int capacity):capacity(capacity)
{
    this->table = new Vector<T>[this->capacity];
}

template <typename T>
HashTable<T>::~HashTable()
{}

template <typename T>
void HashTable<T>::hash(const T x){
    (this->table + this->getkey(x.GetId()))->pb(x);
}

template <typename T>
int HashTable<T>::getkey(int x)const{
    return x % this->capacity;
}

template <typename T>
Vector<T>& HashTable<T>::operator[](const int i){
    if(0<=i && i<100){
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
