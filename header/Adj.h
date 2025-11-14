#pragma once
#include "Word.h"
class Adj : public Word{
    private:
        std::string SoSanhHon;
        std::string SoSanhNhat;
    public:
        Adj(std::string ="",std::string = "");
        ~Adj() override;
        void GetInfoWord() override;
        std::string GetSoSanhHon();
        std::string GetSoSanhNhat();
        void  SetSoSanhHon(const std::string );
        void  SetSoSanhNhat(const std::string );
};