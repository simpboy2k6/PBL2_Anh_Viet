#include "library.h"
using namespace std;
int main(){
    ofstream write;
    ifstream read,voca;
    
    read.open("qlyUser.txt");
    write.open("qlyUser.txt",ios::app);             //khai báo các biến dùng cho chương trình
    voca.open("vocabulary.txt");

    string s,exit,name,password,choice,word;
    Vector_User info;
    HashTable_Word Dictionary;
    int id=0;
    
    welcome();              // hỏi xem muốn đăng nhập hay tạo tài khoản mới
    cin>>s;
    cin.ignore();

    readfile(read,info);    // đọc thông tin các tài khoản hiện có  
    readvocal(Dictionary,voca);  // đọc các từ vựng lưu vào từ điển      
    id = info.getsize();

    if(s=="DK"){
        sign_up(name,password);
        write << name<<","<<password<<","<<++id<<"\n";       // add tài khoản mới vào file qlyUser.txt
        User u(id,name,password);
        info.pb(u);
    }
    id++;

    while(true)

    {
        log_out();
        cin>>exit;
        if(exit=="e") break;                // chạy chương trình
        option();                           // hỏi xem muốn lựa chọn cái gì
        cin>>choice;                            
        if(choice=="Sh"){       
            showinfo(info);
        }else if(choice=="Tr"){
            cout<<"Hay ghi tu bạn muốn tra:";
            cin>>word;
            Search(Dictionary,word);
        }
    }
    
    read.close();
    write.close();
}