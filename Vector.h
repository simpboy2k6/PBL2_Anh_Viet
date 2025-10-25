#pragma once
#include "Word.h"
// Đây là class của vector có kiểu int

class Vector{
    private:
        int capacity;       //  khả năng chứa
        int curr=0;         // số phần tử hiện tại
        int *arr;           
    public:
        Vector(const int =100);
        ~Vector();
        void pb(const int );
        int& operator[](const int );
         
};

// Đây là class của vector có kiểu class Word

class Vector_Word{
    private:
        int capacity;       
        int curr=0;         
        Word *arr;           
    public:
        Vector_Word(const int =100);
        ~Vector_Word();
        void pb(const Word );
        Word& operator[](const int );
        int getsize()const;
         
};

// Đây là class của vector có kiểu string
class Vector_String{
    private:
        int capacity;       
        int curr=0;         
        std::string *arr;           
    public:
        Vector_String(const int =100);
        ~Vector_String();
        void pb(const std::string );
        std::string& operator[](const int );
        int getsize()const;
         
};


