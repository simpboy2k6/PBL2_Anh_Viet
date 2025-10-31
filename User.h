#pragma once
#include <string>
#include"Vector.h"

class User{
    public:
        std::string name;
        std::string password;
        int userid;
        Vector<std::string> history;
    public:
        User(int&, std::string& ,std::string&);
        User();
        ~User();
        void Change_UserName(int&,std::string&);
        void Change_Password(int&,std::string&);
        void showinfo();
        std::string getUsername();
        int GetId() const ;
        std::string getPassword(){ return this->password;}
        void addHistory(const std::string& word); 
        Vector<std::string>& getHistory();
};
