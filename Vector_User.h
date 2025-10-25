#pragma once
#include "User.h"

class Vector_User{
    private:
        int capacity;       
        int curr=0;         
        User *arr;           
    public:
        Vector_User(const int =100);
        ~Vector_User();
        void pb(const User );
        User& operator[](const int );
        int getSize()const;
};