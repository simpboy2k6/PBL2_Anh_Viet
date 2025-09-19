
#include<fstream>
#include "User.h"
using namespace std;

void welcome(){
    cout<<"Ban muon dang ky hay dang nhap(DK:dang ky, DN:Dang nhap)"<<endl;
}
void sign_up(string& name, string& password){
    cout<<"Nhap ten:";
    getline(cin,name);
    cout<<"Nhap password:";
    getline(cin,password);
    User u(name,password);
}
void log_out(){
    cout<<"Ban co muon thoat khoi web ko(e:Exit)\n";
}
int main(){
    ofstream write;
    write.open("qlyUser.txt");
    string s,exit;
    string name;
    string password;
    welcome();

    cin>>s;
    cin.ignore();

    if(s=="DK"){
        sign_up(name,password);
        write << name<<" "<<password<<"\n";
        cout<<name<<" "<<password<<endl;
    }

    while(true)

    {
        log_out();
        cin>>exit;
        if(exit=="e") break;

    }

    write.close();
}