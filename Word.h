#include <string>
class Word{
    private:
        std::string idWord;
        std::string mean;
        std::string example;
        std::string pronounce;
    public:
        Word(std::string ="",std::string ="",std::string="",std::string ="");
        ~Word();
        std::string getidword();
};