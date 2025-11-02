#include<iostream>
#include "Grammar.h"

using namespace std;

// --- Hàm tạo (Constructor) ---
Grammar::Grammar() {
}

// --- Các hàm Set (Dùng khi đọc file) ---

void Grammar::SetName(const string& name) {
    this->ruleName = name;
}

void Grammar::AddFormula(const string& formula) {
    this->formulas.pb(formula); 
}

void Grammar::SetExplanation(const string& expl) {
    this->explanation = expl;
}

void Grammar::AddExample(const string& ex) {
    this->examples.pb(ex); 
}

// --- Các hàm Get (Dùng khi hiển thị) ---

string Grammar::GetName() const {
    return this->ruleName;
}

// Hàm in thông tin chi tiết của quy tắc ra màn hình
void Grammar::GetInfoRule() const {
    cout << "\n+----------------------------------------+" << endl;
    // (Tính toán padding để căn giữa tên quy tắc nếu muốn)
    cout << "| QUY TAC: " << this->ruleName << endl;
    cout << "+----------------------------------------+" << endl;

    // --- In CÔNG THỨC ---
    if (this->formulas.getsize() > 0) { 
        cout << "\n[CONG THUC]\n";
        for (int i = 0; i < this->formulas.getsize(); ++i) {
            cout << "  - " << this->formulas[i] << endl;
        }
    }

    // --- In GIẢI THÍCH ---
    cout << "\n[GIAI THICH]\n";
    cout << "  " << this->explanation << endl;

    // --- In VÍ DỤ ---
    if (this->examples.getsize() > 0) { 
        cout << "\n[VI DU]\n";
        for (int i = 0; i < this->examples.getsize(); ++i) {
            cout << "  - " << this->examples[i] << endl;
        }
    }
    cout << "+----------------------------------------+" << endl;
}