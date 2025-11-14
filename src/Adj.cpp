#include "Adj.h"
#include <iostream>
using namespace std;

Adj::Adj(string a, string b):Word(),SoSanhHon(a),SoSanhNhat(b)
{}
Adj::~Adj(){}

void Adj::GetInfoWord(){
    cout<<this->name<<":\n";
    cout<<"Ý nghĩa:"<<this->mean<<"\n";
    cout<<"Loại:"<<this->type<<"\n";
    cout<<"Câu ví dụ:"<<this->example<<"\n";
    cout<<"So sánh hơn:"<< this->SoSanhHon<<" than ..."<<"\n";
    cout<<"So sánh nhất:"<<"the "<< this->SoSanhNhat<<"\n";
    cout<<"Phát âm:"<<this->pronounce<<"\n";
}

void Adj::SetSoSanhHon(const string s){
    this->SoSanhHon = s;    
}
void Adj::SetSoSanhNhat(const string s){
    this->SoSanhNhat = s;
}
string Adj::GetSoSanhHon(){
    return this->SoSanhHon;
}
string Adj::GetSoSanhNhat(){
    return this->SoSanhNhat;
}