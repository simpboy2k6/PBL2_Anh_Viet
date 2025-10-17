#pragma once
#include"Word.h"
class User{
    public:
        String name;
        String password;
        int userid;
    public:
        User(int&, std::string& ,std::string& ) ;
        User();
        User(int&, String& ,String& ) ;
        ~User();
        void Change_UserName(int&,String&);
        void showinfo();
        std::string getname();
        int getidUser();
        String getname();
};

