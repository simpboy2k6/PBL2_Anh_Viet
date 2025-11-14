#pragma once
#include "Word.h"
class Verb : public Word{
    private:
        std::string V2;
        std::string V3;
    public:
        Verb(std::string ="", std::string = "");
        ~Verb() override;
        void GetInfoWord() override;
        std::string GetV2();
        std::string GetV3();
        void SetV2(const std::string s);
        void SetV3(const std::string s);
};