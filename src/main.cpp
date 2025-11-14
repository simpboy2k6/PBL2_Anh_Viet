#include "library.h"
using namespace std;

int main(){

    SetConsoleOutputCP(65001); // Đặt code page của output (cout)
    SetConsoleCP(65001);       // Đặt code page của input (cin)
   
    User* currentUser = nullptr;
    
    ofstream write,luu_dictionary;
    ifstream read,voca,grammar;
    
    read.open("data/qlyUser.txt");
    voca.open("data/newvocabulary.txt");
    grammar.open("data/grammar.txt");
    string s,exit,name,password,choice,word;
    Vector<User> UserList;
    HashTable<Word*> Dictionary;
    Vector<Grammar> gList;
    int id=0;
    readfile(read,UserList);    // đọc thông tin các tài khoản hiện có
    readGrammar(grammar,gList); // đọc các quy tắc ngữ pháp vào gList
    cout<<"ok\n";
    readvocal(Dictionary,voca);  // đọc các từ vựng lưu vào từ điển
    cout<<"ok\n";
    readGrammar(grammar,gList); // đọc các quy tắc ngữ pháp vào gList
    id = UserList.getsize();

    voca.close();
    grammar.close();
    read.close();

    write.open("data/qlyUser.txt",ios::app);  
    while(true) {
        if (currentUser == nullptr) {
            LoginMenu(currentUser, UserList,id,write);
        }
        
        if (currentUser == nullptr) {
            break; 
        }
        MainMenu(currentUser, Dictionary, gList);
    }
    luu_dictionary.open("data/newvocabulary.txt");
    luu_vocalbulary(Dictionary,luu_dictionary);  // lưu từ điển vào dic.txt
    luu_dictionary.close();
    
    write.close();

    /*ifstream voca;
    HashTable<Word*> Dictionary;
    voca.open("data/newvocabulary.txt");
    readvocal(Dictionary,voca);
    voca.close();
    cout<<"end";*/
}