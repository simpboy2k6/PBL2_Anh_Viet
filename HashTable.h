#pragma once
#include "Vector.h"

// Đây là class của HashTable có kiểu int
class HashTable{
    private:
        int capacity;
        Vector *table;
    public:
        HashTable(const int x=100);
        ~HashTable();
        int getkey(const int )const;
        void hash(const int);
        Vector& operator[](const int );
};

// Đây là class của HashTable có kiểu class Word

class HashTable_Word{
    private:
        int capacity;
        Vector_Word *table;
    public:
        HashTable_Word(const int x=100);
        ~HashTable_Word();
        int getkey(const int )const;
        void hash(Word&);
        Vector_Word& operator[](const int );
};

// Đây là class của HashTable có kiểu class User

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
};
