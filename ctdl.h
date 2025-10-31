#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Point{
    private:
        T x,y;
    public:
        Point(const T,const T);
        Point();
        ~Point();
        void show();
};
using namespace std;

template<typename T>
Point<T>::Point(const T x,const T y){
    this->x = x;
    this->y = y;
}
template<typename  T>
Point<T>::Point(){
}

template<typename T>
Point<T>::~Point(){

}
template<typename T>
void Point<T>::show(){
    cout<<this->x<<this->y<<endl;
}

class co{
    private:
        int x;
    public:
        co(const int );
        co();
        ~co();
        void show();
        void operator=(int x);
        friend ostream& operator<<(ostream&,const co); 
};

co::co(const int x){
    this->x = x;
}
co::co(){}
co::~co(){

}
void co::show(){
    cout<<this->x<<endl;
}
void co::operator=(int x){
    this->x = x;
}
ostream& operator<<(ostream& out, const co c){
    out << c.x;
    out <<"\n";
    return out;
}