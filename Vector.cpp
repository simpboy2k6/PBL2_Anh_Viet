#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int const capacity)
    :capacity(capacity)
{
    this->arr = new int[capacity];
}
Vector::~Vector(){}

void Vector::pb(int const x){
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
