#include "User.h"
#include<iostream>
using namespace std;
User::User(const int x, const string name,const string password)
{
    this->name = name;
    this->password = password;
    this->userid = x;
}

User::User(){
    this->name = "";
    this->password = "";
    this->userid = 0;
}
User::~User(){}
void User::showinfo()
{
    cout<<"Ten:"<<this->name<<", Password: "<<this->password<<", Userid: "<<this->userid<<"\n";

}
string User::getname(){
    return this->name;
}

int User::getidUser(){
    return this->userid;
}

