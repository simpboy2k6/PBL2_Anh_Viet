#include "Word.h"
#include <iostream>
using namespace std;
Word::Word(const int x,String a,String b,Vector_String c,String d,String e)
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

void Word::SetInfoWord(const String a,const String b, Vector_String c,const String d,const String e)
{
    this->name = a; this->type = b; this->mean = c;this->example = d;this->pronounce = e;
}
void Word::SetMean(Vector_String a){
    this->mean = a;
}
void Word::SetExample(const String a){
    this->example=a;
}
void Word::SetName(const String a){
    this->name=a;
}
void Word::SetPronounce(const String a){
    this->pronounce=a;
}
void Word::SetType(const String a){
    this->type=a;
}




