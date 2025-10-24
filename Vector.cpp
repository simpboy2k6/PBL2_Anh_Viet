#include "Vector.h"
#include <iostream>
using namespace std;


// Định nghĩa hàm của vector có kiểu int
Vector::Vector(int const capacity)
    :capacity(capacity)
{
    this->arr = new int[capacity];
}
Vector::~Vector(){}

void Vector::pb(const int x){
    *(this->arr+this->curr) = x;
    this->curr ++;
    if(this->curr == this->capacity){
        int *tmp = new int[this->capacity];
        for(int i=0;i<this->capacity;i++){
            *(tmp+i) = *(this->arr +i);
        }
        delete[] this->arr;
        this->arr = new int[this->capacity *2];
        for(int i=0;i<this->curr;i++){
            *(this->arr+i) = *(tmp +i);
        }
        delete[] tmp;
    }

}
int& Vector::operator[](int const i){
    if(0<=i && i <= this->curr){
        return *(this->arr + i);
    }else cout<<"Out range\n"<<endl;
    return *(this->arr);

}


// Định nghĩa hàm của vector có kiểu class Word
Vector_Word::Vector_Word(int const capacity)
    :capacity(capacity)
{
    this->arr = new Word[capacity];
}
Vector_Word::~Vector_Word(){}

void Vector_Word::pb(const Word x){
    *(this->arr+this->curr) = x;
    this->curr ++;
    if(this->curr == this->capacity){
        Word *tmp = new Word[this->capacity];
        for(int i=0;i<this->capacity;i++){
            *(tmp+i) = *(this->arr +i);
        }
        delete[] this->arr;
        this->arr = new Word[this->capacity *2];
        for(int i=0;i<this->curr;i++){
            *(this->arr+i) = *(tmp +i);
        }
        delete[] tmp;
    }

}
Word& Vector_Word::operator[](int const i){
    if(0<=i && i <= this->curr){
        return *(this->arr + i);
    }else cout<<"Out range\n"<<endl;
    return *(this->arr);

}

int Vector_Word::getsize()const{
    return this->curr;
}

// Định nghĩa hàm của vector có kiểu class User


// Định nghĩa hàm của vector có kiểu string
Vector_String::Vector_String(int const capacity)
    :capacity(capacity)
{
    this->arr = new std::string[capacity];
}
Vector_String::~Vector_String(){}

void Vector_String::pb(const std::string x){
    *(this->arr+this->curr) = x;
    this->curr ++;
    if(this->curr == this->capacity){
        std::string *tmp = new std::string[this->capacity];
        for(int i=0;i<this->capacity;i++){
            *(tmp+i) = *(this->arr +i);
        }
        delete[] this->arr;
        this->arr = new std::string[this->capacity *2];
        for(int i=0;i<this->curr;i++){
            *(this->arr+i) = *(tmp +i);
        }
        delete[] tmp;
    }
}

const std::string& Vector_String::operator[](const int i) const {
    if(0<=i && i <= this->curr){
        return *(this->arr + i);
    }else cout<<"Out range\n"<<endl;
    return *(this->arr);
}

int Vector_String::getsize()const{
    return this->curr;
}


