#include"String.h"

int StringLen(const char* s){ // Hàm trả về độ dài string
    int cnt = 0;
    while (s[cnt] != '\0') {
        cnt++;
    }
    return cnt;
}

void StringCopy(char* S1, const char* S2){  // Hàm copy dữ liệu của S2 vào S1
    int i = 0;
    while (S2[i] != '\0') {
        S1[i] = S2[i];
        i++;
    }
    S1[i] = '\0';
}

String::String(){   // Hàm dựng mặt định
    len = 0;
    data = new char[1];
    data[0] = '\0';
}

String::String(const char* s) {     // Hàm dựng sao chép
    len = StringLen(s);
    data = new char[len + 1];
    StringCopy(data, s);
}

String::String(const String& s) {   // Cũng là hàm dựng sao chép nhưng có thể truyền vào đối tượng String
    len = s.len;
    data = new char[len + 1];
    StringCopy(data, s.data); 
}

String::~String() {     // Hàm hủy 
    delete[] data; 
}

String& String::operator=(const String& s) { // Đa năng hóa toán tử gán
    if (this == &s) {
        return *this;
    }
    delete[] data;
    len = s.len;
    data = new char[len + 1];
    StringCopy(data, s.data);
    return *this;
}

int String::length(){
    return len;
}

const char* String::c_str(){
    return data;
}

bool String::operator==(const String& s){ // Đa năng hóa toán tử ==
    if (len != s.len) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (data[i] != s.data[i]) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const String& s) { // Đa năng hóa toán tử xuất
    os << s.data;
    return os;
}