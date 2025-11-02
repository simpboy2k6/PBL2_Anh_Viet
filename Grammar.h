#pragma once
#include <string>
#include "Vector.h"

class Grammar {
private:
    std::string ruleName;
    Vector<std::string> formulas; 
    std::string explanation;
    Vector<std::string> examples;

public:
    Grammar();
    
    // Hàm Set
    void SetName(const std::string&);
    void AddFormula(const std::string&);
    void SetExplanation(const std::string&);
    void AddExample(const std::string&);

    // Hàm Get
    std::string GetName() const;
    void GetInfoRule() const; 
};