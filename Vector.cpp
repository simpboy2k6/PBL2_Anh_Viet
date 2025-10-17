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


// Định nghĩa hàm của vector có kiểu class User

Vector_User::Vector_User(int const capacity)
    :capacity(capacity)
{
    this->arr = new User[capacity];
}
Vector_User::~Vector_User(){}

void Vector_User::pb(const User x){
    *(this->arr+this->curr) = x;
    this->curr ++;
    if(this->curr == this->capacity){
        User *tmp = new User[this->capacity];
        for(int i=0;i<this->capacity;i++){
            *(tmp+i) = *(this->arr +i);
        }
        delete[] this->arr;
        this->arr = new User[this->capacity *2];
        for(int i=0;i<this->curr;i++){
            *(this->arr+i) = *(tmp +i);
        }
        delete[] tmp;
    }

}
User& Vector_User::operator[](int const i){
    if(0<=i && i <= this->curr){
        return *(this->arr + i);
    }else cout<<"Out range\n"<<endl;
    return *(this->arr);

}



