#include "Word.h"
#include <iostream>
using namespace std;
int countname;
Word::Word(const int x,string a,string b,string c,string d,string e)
    :idWord(x),name(a),type(b),mean(c),example(d),pronounce(e)
{}
Word::~Word(){}

int Word::getidword(){
    return this->idWord;
}

void Word::GetInfoWord(){
    cout<<this->name<<":\n";
    cout<<"Ý nghĩa:"<<this->mean<<"\n";
    cout<<"Loại:"<<this->type<<"\n";
    cout<<"Câu ví dụ:"<<this->example<<"\n";
    cout<<"Phát âm:"<<this->pronounce<<"\n";
}

void Word::SetInfoWord(const string a,const string b, const string c,const string d,const string e)
    
{
    this->name =a;this->type=b;this->mean = c;this->example = d;this->pronounce = e;
    countname = 0;
    for(int i=0;i<a.size();i++){
        countname +=((int) a[i])*(i+1);
    }
    this->idWord = countname;
}
void Word::SetMean(const string a){
    this->mean=a;
}
void Word::SetExample(const string a){
    this->example=a;
}
void Word::SetName(const string a){
    this->name=a;
    countname = 0;
    for(int i=0;i<a.size();i++){
        countname +=((int) a[i])*(i+1);
    }
    this->idWord = countname;
}
void Word::SetPronounce(const string a){
    this->pronounce=a;
}
void Word::SetType(const string a){
    this->type=a;
}




