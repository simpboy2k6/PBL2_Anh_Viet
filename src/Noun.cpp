#include "Noun.h"
#include <iostream>
using namespace std;

Noun::Noun(string b,string s):Word()
{
    this->DemDuoc = b;
    this->SoNhieu = s;
}
Noun::~Noun(){
}

void Noun::GetInfoWord(){
    cout<<this->name<<":\n";
    cout<<"Ý nghĩa:"<<this->mean<<"\n";
    cout<<"Loại:"<<this->type<<"\n";
    cout<<this->DemDuoc<<"\n";
    cout<<"Dạng số nhiều:"<< this->SoNhieu<<"\n";
    cout<<"Câu ví dụ:"<<this->example<<"\n";
    cout<<"Phát âm:"<<this->pronounce<<"\n";
}

string Noun::GetSoNhieu(){
    return this->SoNhieu;
}
string Noun::GetDemDuoc(){
    return this->DemDuoc;
}
void Noun::SetDemDuoc(const string b){
    this->DemDuoc = b;
}

void Noun::SetSoNhieu(const string s){
    this->SoNhieu = s;
}
