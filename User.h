#include"Word.h"
class User{
    public:
        String name;
        String password;
        int userid;
    public:
        User(int&, String& ,String& ) ;
        ~User();
        void Change_UserName(int&,String&);
        void showinfo();
        String getname();
};

