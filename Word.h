#include"String.h"
#include"Vector.h"

class Word{
    private:
        int idWord;
        String name;
        Vector_String mean;
        String example;
        String pronounce;
        String type;
    public:
        Word(const int =0,String ="",String = "",Vector_String,String ="",String ="");
        ~Word();
        int getidword();
        void GetInfoWord();
        void SetName(const String);
        void SetMean(Vector_String);
        void SetExample(const String);
        void SetPronounce(const String);
        void SetType(const String);
        void SetInfoWord(const String,const String,Vector_String,const String,const String);
};