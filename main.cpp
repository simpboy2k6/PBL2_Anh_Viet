#include<fstream>
#include "library.h"
/*void welcome(){
    cout<<"Ban muon dang ky hay dang nhap(DK:dang ky, DN:Dang nhap)"<<endl;
}

void sign_up(string& name, string& password){
    cout<<"Nhap ten:";
    getline(cin,name);
    cout<<"Nhap password:";
    getline(cin,password);
}

void log_out(){
    cout<<"Ban co muon thoat khoi web ko(e:Exit)\n";
}*/
int main(){
    ofstream write;
    write.open("qlyUser.txt",ios::app);
    string s,exit;
    string name;
    string password;
    welcome();

    cin>>s;
    cin.ignore();

    if(s=="DK"){
        sign_up(name,password);
        write << name<<" "<<password<<"\n";
    }

    while(true)

    {
        log_out();
        cin>>exit;
        if(exit=="e") break;

    }

    write.close();
}