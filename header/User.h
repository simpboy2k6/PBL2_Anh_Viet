#pragma once
#include <string>
#include"Vector.h"

class User{
    private:
        std::string name;
        std::string password;
        int userid;
        Vector<std::string> history;
    public:
        User(int=0, std::string ="",std::string ="");
        ~User();
        void showinfo();
        std::string getUsername();
        int GetId() const ;
        std::string getPassword(){ return this->password;}
        void addHistory(const std::string& word); 
        Vector<std::string>& getHistory();
        void SetUserName(std::string);
        void SetUserPassword(std::string);
        void SetUserid(const int );
        friend std::ostream& operator<< (std::ostream&, const User&);
};
