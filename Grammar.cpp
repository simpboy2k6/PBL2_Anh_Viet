#include "Grammar.h"

// --- Hàm tạo (Constructor) ---
Grammar::Grammar() {
    // Để trống. Các thành viên (Vector_String, std::string)
    // sẽ tự động gọi hàm tạo mặc định của chúng.
}

// --- Các hàm Set (Dùng khi đọc file) ---

void Grammar::SetName(const std::string& name) {
    this->ruleName = name;
}

void Grammar::AddFormula(const std::string& formula) {
    this->formulas.pb(formula); // pb là push_back
}

void Grammar::SetExplanation(const std::string& expl) {
    this->explanation = expl;
}

void Grammar::AddExample(const std::string& ex) {
    this->examples.pb(ex); // pb là push_back
}

// --- Các hàm Get (Dùng khi hiển thị) ---

std::string Grammar::GetName() const {
    return this->ruleName;
}

// Hàm in thông tin chi tiết của quy tắc ra màn hình
void Grammar::GetInfoRule() const {
    std::cout << "\n+----------------------------------------+" << std::endl;
    // (Tính toán padding để căn giữa tên quy tắc nếu muốn)
    std::cout << "| QUY TAC: " << this->ruleName << std::endl;
    std::cout << "+----------------------------------------+" << std::endl;

    // --- In CÔNG THỨC ---
    if (this->formulas.getsize() > 0) { // getsize() là hàm lấy kích thước của Vector
        std::cout << "\n[CONG THUC]\n";
        for (int i = 0; i < this->formulas.getsize(); ++i) {
            std::cout << "  - " << this->formulas[i] << std::endl;
        }
    }

    // --- In GIẢI THÍCH ---
    std::cout << "\n[GIAI THICH]\n";
    std::cout << "  " << this->explanation << std::endl;

    // --- In VÍ DỤ ---
    if (this->examples.getsize() > 0) { // getsize() là hàm lấy kích thước của Vector
        std::cout << "\n[VI DU]\n";
        for (int i = 0; i < this->examples.getsize(); ++i) {
            std::cout << "  - " << this->examples[i] << std::endl;
        }
    }
    std::cout << "+----------------------------------------+" << std::endl;
}