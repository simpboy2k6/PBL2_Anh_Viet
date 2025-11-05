#include "library.h"
using namespace std;
// các biến được sử dụng lại nhiều lần
int countword,value;
int key;
Word W;
string HistoryDir = "User_history/";
ifstream CurrentUserHistoryDirRead;
ofstream CurrentUserHistoryDirWrite;

void option()
{
    cout<<"Ban muon lua chon option nao\n";
    cout<<"Tra tu(Tr),Tra Ngu Phap(NP),Xem Lich Su(LS),show(Sh)\n"; 
}
void readfile(ifstream& in,Vector<User>& v)
{
    string s="1",init;
    int i=0;
    User u(i,init,init);
    //int k=0;
    while(getline(in,s)){             // kiểm tra xem luồng stream trong file in đã hết chưa
        //k++;
        if(s=="")continue;
        i=0;
        stringstream ss(s);
        while(getline(ss,s,',')){
            if(i==0){
                u.name=s;
            }else if(i==1){
                u.password=s;
            }else u.userid= stoi(s);
            i++;
        }
        v.pb(u);
    }
    //cout<<"chay trong "<<k<<"lan"<<endl;
}
void showinfo(Vector<User>& v)
{
    int k=v.getsize();
    for(int i=0;i<k;i++)
    {
        v[i].showinfo();
    }
}

void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void pauseScreen() {
    cout << "\n(Nhan Enter de tiep tuc...)" << endl;
    cin.ignore(10000, '\n'); // Xóa bộ đệm và chờ Enter
    if (cin.gcount() == 0) {
        string dummy;
        getline(cin, dummy);
    }
}

void sign_up(Vector<User>& UserList, ofstream& write, int& id)
{
    string name="", password="", confirm_password; 
    cout << "Nhập tên đăng nhập: ";
    getline(cin, name);
    for(int i=0;i<UserList.getsize();i++){
        if(UserList[i].getUsername()==name){
            cout<<"Tên này đã có người sử dụng. Vui lòng thử lại!\n";
            pauseScreen();
            return;
        }
    }
    cout << "Nhập lại mật khẩu: ";
    getline(cin, password);
    if(name=="" || password==""){
        cout<<"Chưa nhập mật khẩu hoặc tên đăng nhập! \n";
        pauseScreen();
        return;
    }
    cout << "Nhập lại mật khẩu: ";
    getline(cin, confirm_password);
    if (password == confirm_password) {
        ++id;
        write << name << "," << password << "," << id << "\n"; 

        write.flush(); // Đảm bảo ghi ngay vào file

        User u(id, name, password); // Tạo user mới
        UserList.pb(u);

        cout << "Đăng ký thành công!" << endl;
    } else {
        cout << "Mật khẩu không khớp. Vui lòng thử lại" << endl;
    }
    pauseScreen(); // Thêm tạm dừng để người dùng đọc thông báo
}

void log_out()
{
    cout<<"Ban co muon thoat khoi web ko(e:Exit)\n";
}

void login(User*& currentUser, Vector<User>& UserList, int& id) {
    string username, password;
    cout << "--- DANG NHAP ---\n";
    cout << "Nhap ten dang nhap: ";
    getline(cin, username);
    cout << "Nhap mat khau: ";
    getline(cin, password);

    User NewUser(id,username, password);
    
    for (int i = 0; i < UserList.getsize(); i++){
        if (UserList[i].getUsername() == username && UserList[i].getPassword() == password) {
            currentUser = &UserList[i];
            break;
        }
    }   

    if (currentUser != nullptr) {
        cout << "\nDang nhap thanh cong! Chao mung tro lai, " << currentUser->getUsername() << "!" << endl;

        string s = HistoryDir+currentUser->getUsername();
        CurrentUserHistoryDirRead.open(s);      // mở file history của User 

        //cout<<"check name:"<<s<<endl;
        while(getline(CurrentUserHistoryDirRead,s)){
            currentUser->addHistory(s);         // đọc dữ liệu trong file đó
        }
        CurrentUserHistoryDirRead.close();          // đóng file history của User

    } else{
        cout << "\nTen dang nhap hoac mat khau khong dung." << endl;
    }
    pauseScreen();
}

void LoginMenu(User*& currentUser, Vector<User>& UserList, int& id, ofstream& write) {
    int choice = 0;
    while (currentUser == nullptr){
        clearScreen();
        cout << "+----------------------------------------+\n";
        cout << "|                                        |\n";
        cout << "|      CHUONG TRINH TU DIEN ANH-VIET     |\n";
        cout << "|                                        |\n";
        cout << "+----------------------------------------+\n\n";
        cout << "[1] Dang nhap\n";
        cout << "[2] Dang ky\n";
        cout << "[3] Thoat\n\n";
        cout << "Vui long chon: ";
        
        string input;
        getline(cin, input);       // nhập choice
        
        choice = (input.length() > 0) ? (input.c_str()[0] - '0') : 0;


        switch (choice) {
            case 1: login(currentUser,UserList,id); break;
            case 2: sign_up(UserList, write, id); break;
            case 3: 
                cout << "Tam biet!" << endl;

                return;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
                pauseScreen();
        }
    }
}

void MainMenu(User*& currentUser, HashTable<Word>& Dictionary, Vector<Grammar>& gList) {
    int choice = 0;
    string s;
    while (true) {
        clearScreen();
        cout << "+----------------------------------------+\n";
        cout << "|                                        |\n";
        cout << "|          TU DIEN ANH - VIET            |\n";
        cout << "|                                        |\n";
        cout << "|";
        int total_width = 39;
        int text_length = 12 + currentUser->getUsername().length();
        int pad = total_width - text_length;
        for (int i = 0; i < pad; i++) {
            cout << " ";
        }
        cout << "Chao mung, " << currentUser->getUsername();
        cout << "  |\n";
        cout << "+----------------------------------------+\n\n";
        cout << "[1] Tra tu\n";
        cout << "[2] Tra Ngu Phap\n";
        cout << "[3] Xem Lich Su\n";
        cout << "[4] Dang xuat\n\n";
        cout << "Vui long chon: ";

        string input;
        getline(cin, input);
        
        choice = (input.length() > 0) ? (input.c_str()[0] - '0') : 0;

        switch (choice) {
            case 1:
                SearchWord(Dictionary,currentUser);
                //pauseScreen();
                break;
            case 2:
                SearchGrammar(gList,currentUser);
                //pauseScreen();
                break;
            case 3:
                viewHistory(currentUser);
                //pauseScreen();
                break;
            case 4:
                s = HistoryDir + currentUser->getUsername();
                CurrentUserHistoryDirWrite.open(s);             // mở file history của User để ghi

                for(int i=0;i<currentUser->getHistory().getsize();i++){
                    CurrentUserHistoryDirWrite << currentUser->getHistory()[i]<<"\n"; // ghi vào file history của user
                    
                }
                CurrentUserHistoryDirWrite.close();

                currentUser->getHistory().Erase_Vector();  // xóa đi dữ liệu của Vector String trong currentUser 
                currentUser = nullptr;
                cout << "Dang xuat thanh cong!" << endl;
                pauseScreen();
                return;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
                pauseScreen();
        }
    }
}
// Hàm xem lịch sử tra cứu
void viewHistory(User*& currentUser) {
    clearScreen();
    cout << "+----------------------------------------+\n";
    cout << "|             LICH SU TRA CUU            |\n";
    cout << "+----------------------------------------+\n\n";

    if (currentUser != nullptr) {
        Vector<string>& historyList = currentUser->getHistory(); // Lấy danh sách lịch sử
        if (historyList.getsize() == 0) {
            cout << "Ban chua tra cuu tu nao.\n";
        } else {
            cout << "Cac tu ban da tra:\n";
            for (int i = 0; i < historyList.getsize(); ++i) {
                cout << "  - " << historyList[i] << endl; // Truy cập và in từng từ
            }
        }
    } else {
        cout << "Loi: Khong tim thay thong tin nguoi dung.\n"; 
    }

    pauseScreen();
}

// T cập nhật hàm Search để lưu lịch sử tìm kiếm vào User hiện tại
void Search(HashTable<Word>& Dictionary, string& word, User*& currentUser)
{
    countword = 0;value =0;
    for(int i=0;i<word.size();i++){
        word[i]= tolower(word[i]);
        value += (i+1)* ((int)word[i]);         // chuyển đổi dạng string thành tổng các chữ số 
    }                                               // theo công thức 

    key = Dictionary.getkey(value);             // lấy key để hash
    /*for(int i=0;i<Dictionary.getcapacity();i++){
        cout<<"iiiiii:"<<i<<endl;
        for(int j=0;j<Dictionary[i].getsize();j++){
            cout<<Dictionary[i][j].getidword()<<endl;
            cout<<Dictionary[i][j].GetName()<<endl;
        }
    }*/
    //cout<<"Day la tu can tìm:"<<word<<"\n";
    //cout<<"value:"<<value<<","<<"key:"<<key<<endl;
    for(int i=0;i<Dictionary[key].getsize();i++){
        if(Dictionary[key][i].GetId() == value && word == Dictionary[key][i].GetName()){  
                   
            Dictionary[key][i].GetInfoWord();
            if(countword==0)currentUser->addHistory(word); // Lưu từ tìm kiếm vào lịch sử của User hiện tại
            countword++;         
        }
    }
    if(countword==0){
        cout<<"Không có từ bạn tìm kiếm ở trong từ điển này\n";

    }
}

void readvocal(HashTable<Word>& Dictionary,ifstream& vocabulary)
{
    int i;
    string s;
    while(getline(vocabulary,s)){
        if(s=="") continue;
        i=0;
        stringstream ss(s);
        while(getline(ss,s,',')){
            if(i==1){
                W.SetName(s);
            }else if(i==3){
                W.SetMean(s);
            }else if(i==2){
                W.SetType(s);
            }else if(i==4){
                W.SetExample(s);
            }else if(i==5){
                W.SetPronounce(s);
            }
            i++;
        }
        Dictionary.hash(W);
    }

}
void luu_vocalbulary(HashTable<Word>& Dictionary, ofstream& write){
    for(int i=0; i <Dictionary.getcapacity();i++){
        for(int j=0;j<Dictionary[i].getsize();j++){
            write<<i<<",";
            write<<Dictionary[i][j].GetName()<<",";
            write<<Dictionary[i][j].GetType()<<",";
            write<<Dictionary[i][j].GetMean()<<",";
            write<<Dictionary[i][j].GetExample()<<",";
            write<<Dictionary[i][j].GetPronounce()<<"\n";
        }
    }
}
// Hàm đọc file ngữ pháp 
void readGrammar(ifstream& grammar_file, Vector<Grammar>& gList) {
    string line, rulePart, subPart; 
    
    while (getline(grammar_file, line)) { 
        if (line == "") continue;

        Grammar newRule;
        stringstream ss(line);
        int partIndex = 0;

        // Tách dòng chính bằng dấu '|' vì dấu ',' có thể xuất hiện trong phần nghĩa hoặc ví dụ
        while (getline(ss, rulePart, '|')) {
            if (partIndex == 0) {
                newRule.SetName(rulePart);

            } else if (partIndex == 1) { // PHẦN CÔNG THỨC MỚI
                stringstream ss_formulas(rulePart);
                while (getline(ss_formulas, subPart, ';')) { // Tách công thức bằng dấu ';'
                    newRule.AddFormula(subPart);
                }

            } else if (partIndex == 2) { // GIẢI THÍCH
                newRule.SetExplanation(rulePart);

            } else if (partIndex == 3) { //  VÍ DỤ
                stringstream ss_examples(rulePart);
                while (getline(ss_examples, subPart, ';')) { 
                    newRule.AddExample(subPart);
                }
            }
            partIndex++;
        }
        gList.pb(newRule); 
    }
}

void FindGrammar(Vector<Grammar>& gList,User*& currentUser) {
    clearScreen();
    cout << "+----------------------------------------+\n";
    cout << "|         TIM KIEM QUY TAC NGU PHAP      |\n";
    cout << "+----------------------------------------+\n\n";
    cout << "Nhap ten quy tac can tim (go 0 de quay lai): ";
    string keyword;
    getline(cin, keyword);

    if (keyword == "0") return;

    for(char &c : keyword) { c = tolower(c); }

    bool found = false;
    for (int i = 0; i < gList.getsize(); ++i) {
        string ruleName = gList[i].GetName();
        for(char &c : ruleName) { c = tolower(c); }
        if (ruleName.find(keyword) != string::npos) {
            gList[i].GetInfoRule(); // In thông tin nếu tìm thấy
            currentUser->addHistory(gList[i].GetName());
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay quy tac ngu phap phu hop.\n";
    }
    pauseScreen();
}

// Hàm hiển thị tất cả các quy tắc ngữ pháp và cho phép người dùng chọn để xem chi tiết
void AllGrammar(Vector<Grammar>& gList,User*& currentUser) {
    clearScreen();
    cout << "+----------------------------------------+\n";
    cout << "|       DANH SACH TAT CA QUY TAC         |\n";
    cout << "+----------------------------------------+\n\n";

    for (int i = 0; i < gList.getsize(); ++i) {
        cout << "  [" << (i + 1) << "] " << gList[i].GetName() << endl;
    }
    
    cout << "\nChon mot so de xem chi tiet (hoac 0 de thoat): ";
    int ruleChoice;
    cin >> ruleChoice;
    cin.ignore(10000, '\n'); // Xóa bộ đệm sau khi nhập số

    if (ruleChoice > 0 && ruleChoice <= gList.getsize()) {
        clearScreen();
        gList[ruleChoice - 1].GetInfoRule();
        currentUser->addHistory(gList[ruleChoice-1].GetName());
    }
    pauseScreen();
}

void SearchGrammar(Vector<Grammar>& gList,User*& currentUser) {
    while (true) {
        clearScreen();
        cout << "+----------------------------------------+\n";
        cout << "|             TRA CUU NGU PHAP           |\n";
        cout << "+----------------------------------------+\n\n";
        cout << "[1] Tim kiem theo ten quy tac\n";
        cout << "[2] Xem danh sach tat ca quy tac\n";
        cout << "[0] Quay lai Menu Chinh\n\n";
        cout << "Vui long chon: ";

        string input;
        getline(cin, input);
        int choice = (input.length() > 0) ? (input.c_str()[0] - '0') : 0;

        switch (choice) {
            case 1:
                FindGrammar(gList,currentUser); 
                break;
            case 2:
                AllGrammar(gList,currentUser); 
                break;
            case 0:
                return;
            default:
                cout << "Lua chon khong hop le.\n";
                pauseScreen();
        }
    }
}

void SearchWord(HashTable<Word>& Dictionary, User*& currentUser)
{
    clearScreen();
    cout << "+----------------------------------------+\n";
    cout << "|             TRA CUU TU VUNG            |\n";
    cout << "+----------------------------------------+\n\n";
    cout << "Hay ghi tu ban muon tra (hoac go '0' de quay lai): ";

    string word;
    getline(cin, word);
    if (word == "0") {
        return; 
    }
    Search(Dictionary, word, currentUser);
    pauseScreen();
}