#include "library.h"
class User{
    protected:
        string name;
        string password;
        int userid;
    public:
        User(string&,string&) ;
        ~User();
};