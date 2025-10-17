#include "Vector.h"
#include "Word.h"
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

// Định nghĩa hàm của vector có kiểu class String
Vector_String::Vector_String(int const capacity)
    :capacity(capacity)
{
    this->arr = new String[capacity];
}
Vector_String::~Vector_String(){}

void Vector_String::pb(const String x){
    *(this->arr+this->curr) = x;
    this->curr ++;
    if(this->curr == this->capacity){
        String *tmp = new String[this->capacity];
        for(int i=0;i<this->capacity;i++){
            *(tmp+i) = *(this->arr +i);
        }
        delete[] this->arr;
        this->arr = new String[this->capacity *2];
        for(int i=0;i<this->curr;i++){
            *(this->arr+i) = *(tmp +i);
        }
        delete[] tmp;
    }

}

String& Vector_String::operator[](int const i){
    if(0<=i && i <= this->curr){
        return *(this->arr + i);
    }else cout<<"Out range\n"<<endl;
    return *(this->arr);

}

ostream& operator<<(ostream& os, const Vector_String& vec) {
    for (int i = 0; i < vec.curr; ++i) {
        os << vec.arr[i];
        if (i < vec.curr - 1) {
            os << ", "; 
        }
    }
    return os;
}

Vector_String& Vector_String::operator=(const Vector_String& vec) {
    if (this == &vec) {
        return *this; 
    }
    delete[] this->arr; 
    this->capacity = vec.capacity;
    this->curr = vec.curr;
    this->arr = new String[this->capacity];
    for (int i = 0; i < this->curr; ++i) {
        this->arr[i] = vec.arr[i]; 
    }
    return *this;
}
