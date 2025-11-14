#pragma once
#include "Word.h"
class Noun : public Word{
    private:
        std::string DemDuoc;
        std::string SoNhieu;
    public:
        Noun(std::string ="",std::string ="");
        ~Noun() override;
        void GetInfoWord() override;
        std::string GetSoNhieu();
        std::string GetDemDuoc();
        void SetDemDuoc(const std::string);
        void SetSoNhieu(const std::string);
};