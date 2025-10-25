#pragma once 
#include <string>

class Word{
    private:
        int idWord;
        std::string name;
        std::string mean;
        std::string example;
        std::string pronounce;
        std::string type;
    public:
        Word(const int =0,std::string ="",std::string ="",std::string="",std::string ="",std::string ="");
        ~Word();
        int getidword();
        void GetInfoWord();
        void SetName(const std::string);
        void SetMean(const std::string);
        void SetExample(const std::string);
        void SetPronounce(const std::string);
        void SetType(const std::string);
        void SetInfoWord(const std::string,const std::string,const std::string,const std::string,const std::string);
        std::string GetName() const ;
        std::string GetMean()const ;
        std::string GetExample()const;
        std::string GetPronounce() const ;
        std::string GetType()const;
};