#pragma once
#include <string>
#include <iostream> // Thêm thư viện này để GetInfoRule có thể dùng cout
#include "Vector.h" // Giả sử file này định nghĩa Vector_String

class Grammar {
private:
    std::string ruleName;
    Vector<std::string> formulas;    // <--- THÊM DÒNG NÀY
    std::string explanation;
    Vector<std::string> examples;

public:
    Grammar();
    
    // Hàm Set
    void SetName(const std::string& name);
    void AddFormula(const std::string& formula); // <--- THÊM HÀM NÀY
    void SetExplanation(const std::string& expl);
    void AddExample(const std::string& ex);

    // Hàm Get
    std::string GetName() const;
    void GetInfoRule() const; // Hàm này sẽ được cập nhật
};