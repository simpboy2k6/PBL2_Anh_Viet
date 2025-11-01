#include "library.h"
using namespace std;




int main(){

    SetConsoleOutputCP(65001); // Đặt code page của output (cout)
    SetConsoleCP(65001);       // Đặt code page của input (cin)
   
    User* currentUser = nullptr;
    
    ofstream write,luu_dictionary;
    ifstream read,voca,grammar;
    
    read.open("qlyUser.txt");
    write.open("qlyUser.txt",ios::app);             //khai báo các biến dùng cho chương trình
    voca.open("vocabulary.txt");
    grammar.open("grammar.txt");
    luu_dictionary.open("dic.txt");
    string s,exit,name,password,choice,word;
    Vector<User> UserList;
    HashTable<Word> Dictionary;
    Vector<Grammar> gList;
    int id=0;

    readfile(read,UserList);    // đọc thông tin các tài khoản hiện có
    readvocal(Dictionary,voca);  // đọc các từ vựng lưu vào từ điển
    readGrammar(grammar,gList); // đọc các quy tắc ngữ pháp vào gList
    id = UserList.getsize();
    
//    id = info.getsize();

/*   if(s=="DK"){
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
    }*/

    while(true) {
        if (currentUser == nullptr) {
            LoginMenu(currentUser, UserList,id,write);
        }

        if (currentUser == nullptr) {
            break; 
        }
        MainMenu(currentUser, Dictionary, gList);
    }

    luu_vocalbulary(Dictionary,luu_dictionary);
    read.close();
    write.close();
    voca.close();
    grammar.close();
    luu_dictionary.close();
}