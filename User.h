#pragma once
#include <string>

class User{
    public:
        std::string name;
        std::string password;
        int userid;
    public:
        User(int&, std::string& ,std::string& ) ;
        User();
        ~User();
        void Change_UserName(int&,std::string&);
        void showinfo();
        std::string getname();
        int getidUser();
};

