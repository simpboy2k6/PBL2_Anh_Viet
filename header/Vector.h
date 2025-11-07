#pragma once
#include "Word.h"
template<typename T>

class Vector{
    private:
        int capacity;       //  khả năng chứa
        int curr=0;         // số phần tử hiện tại
        T *arr;           
    public:
        Vector(const int =100);
        ~Vector();
        void pb(const T );
        T& operator[](const int );
        void Erase_Vector();
        int getsize()const;
        const T& operator[](int index) const;
        void Erase(const int);
        
};

// định nghĩa các hàm của class vector
template<typename T>
Vector<T>::Vector(int const capacity)
    :capacity(capacity)
{
    this->arr = new T[capacity];
}
template<typename T>
Vector<T>::~Vector(){}

template<typename T>
void Vector<T>::pb(const T x){
    *(this->arr+this->curr) = x;
    this->curr ++;

    if(this->curr == this->capacity){
        T *tmp = new T[this->capacity];
        for(int i=0;i<this->capacity;i++){
            *(tmp+i) = *(this->arr +i);
        }
        delete[] this->arr;
        this->arr = new T[this->capacity*2];
        this->capacity *=2;
        for(int i=0;i<this->curr;i++){
            *(this->arr+i) = *(tmp +i);
        }
        delete[] tmp;
    }

}

template<typename T>
T& Vector<T>::operator[](int const i){
    if(0<=i && i <= this->curr){
        return *(this->arr + i);
    }else std::cout<<"Out range\n";
    return *(this->arr);

}

template<typename T>
void Vector<T>::Erase_Vector(){
    delete[] this->arr;
    this->arr = new T[this->capacity];
    this->curr=0;
}

template<typename T>
int Vector<T>::getsize()const{
    return this->curr;
}

template<typename T>
const T& Vector<T>::operator[](int index) const {
        return arr[index];
}

template<typename T>
void Vector<T>::Erase(const int x){
    if(x<0 || x >=curr){
        std::cout<<"Segmentation fault\n";
        return;
    }
    for(int i = x;i<this->curr;i++){
        *(this->arr +i)= *(this->arr+i+1);
    }
    curr--;
}

/*int main(){
    Vector<int> v;
    v.pb(1);
    v.pb(2);
    v.pb(3);
    std::cout<<v[1]<<"\n";
    v.Erase(1);
    std::cout<<v[1]<<"\n";
}*/
