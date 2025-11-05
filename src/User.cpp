#include "User.h"
#include<iostream>
using namespace std;

User::User(int& id, string& name,string& password)
{
    this->name = name;
    this->password = password;
    this->userid = id;
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
string User::getUsername(){
    return this->name;
}

int User::GetId() const{
    return this->userid;
}

void User::addHistory(const std::string& word) {
    this->history.pb(word);
}

Vector<string>& User::getHistory(){
    return this->history;
}
