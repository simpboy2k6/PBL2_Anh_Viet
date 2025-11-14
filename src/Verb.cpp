#include "Verb.h"
#include<iostream>
using namespace std;

Verb::Verb(string V2, string V3):Word(),V2(V2),V3(V3)
{}
Verb::~Verb(){

}
void Verb::GetInfoWord(){
    cout<<this->name<<":\n";
    cout<<"Ý nghĩa:"<<this->mean<<"\n";
    cout<<"Loại:"<<this->type<<"\n";
    cout<<"Động từ V2:"<<this->V2<<"\n";
    cout<<"Động từ V3 :"<<this->V3<<"\n";
    cout<<"Câu ví dụ:"<<this->example<<"\n";
    cout<<"Phát âm:"<<this->pronounce<<"\n";
}

void Verb::SetV2(const string s){
    this->V2 = s;
}

void Verb::SetV3(const string s){
    this->V3 = s;
}
string Verb::GetV2(){
    return this->V2;
}
string Verb::GetV3(){
    return this->V3;
}