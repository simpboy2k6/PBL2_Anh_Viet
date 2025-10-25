#include "Vector_User.h"
#include<iostream>
using namespace std;

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

int Vector_User::getSize()const{
    return this->curr;
}
