#include "library.h"
using namespace std;

User* currentUser = nullptr;
vector<User> UserList;

int main(){
    ofstream write;
    ifstream read,voca;
    
    read.open("qlyUser.txt");
    write.open("qlyUser.txt",ios::app);             //khai báo các biến dùng cho chương trình
    voca.open("vocabulary.txt");

    string s,exit,name,password,choice;
    int id=0;
    
    
    read.close();
    write.close();
}