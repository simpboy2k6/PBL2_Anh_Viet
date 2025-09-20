#include "library.h"
using namespace std;
int main(){
    ofstream write;
    ifstream read;
    read.open("qlyUser.txt");
    write.open("qlyUser.txt",ios::app);
    string s,exit,name,password,choice;
    vector<User> info;
    int id=0;
    welcome();
    cin>>s;
    cin.ignore();
    readfile(read,info);
    id = info.size();

    if(s=="DK"){
        sign_up(name,password);
        write << name<<","<<password<<","<<++id<<"\n";
        User u(id,name,password);
        info.push_back(u);
    }
    id++;
    while(true)

    {
        log_out();
        cin>>exit;
        if(exit=="e") break;                // chạy chương trình
        option();
        cin>>choice;
        if(choice=="Sh"){
            showinfo(info);
        }
    }
    read.close();
    write.close();
}