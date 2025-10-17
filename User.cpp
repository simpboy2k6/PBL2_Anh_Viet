#include "User.h"
#include<iostream>
using namespace std;
User::User(int& id, string& name,string& password)
{
    this->name = name;
    this->password = password;
    this->userid = id;
}

User::User()
    :userid(0),name(""),password("")
{

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