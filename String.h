#include <iostream>

using namespace std;

class String{
private:
    char* data; 
    int len;
public:
    String();          
    String(const char*);        
    String(const String&);
    ~String();
    String& operator=(const String&);
    int length();
    const char* c_str();
    bool operator==(const String&);
    friend ostream& operator<<(ostream&, const String&);
    String& operator+=(char);
};