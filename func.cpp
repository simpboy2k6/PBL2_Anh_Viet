#include "library.h"

void welcome(){
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
}

