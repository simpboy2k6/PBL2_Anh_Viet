class String;
class Word;

// Đây là class của vector có kiểu int
class Vector{
    private:
        int capacity;       //  khả năng chứa
        int curr=0;         // số phần tử hiện tại
        int *arr;           
    public:
        Vector(const int =100);
        ~Vector();
        void pb(const int );
        int& operator[](const int );
         
};

// Đây là class của vector có kiểu class Word

class Vector_Word{
    private:
        int capacity;       
        int curr=0;         
        Word *arr;           
    public:
        Vector_Word(const int =100);
        ~Vector_Word();
        void pb(const Word );
        Word& operator[](const int );  
};

// Đây là class của vector có kiểu class String
class Vector_String{
    private:
        int capacity;       
        int curr=0;         
        String *arr;           
    public:
        Vector_String(const int = 100);
        ~Vector_String();
        void pb(const String );
        String& operator[](const int );  
        friend ostream& operator<<(ostream&, const Vector_String&);
        Vector_String& operator=(const Vector_String&);
};