#include "User.h"
using namespace std;

User::User(int id, string name,string password)
{
    this->name = name;
    this->password = password;
    this->userid = id;
}

User::~User(){}
void User::SetUserName(string name)
{
    this->name = name;
}
void User::SetUserPassword(string pass)
{
    this->password = pass;
}
void User::SetUserid(const int id){
    this->userid = id;
}
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
ostream& operator<< (ostream& out, const User& u){
    out <<u.GetId()<<"\n";
    return out;
}
