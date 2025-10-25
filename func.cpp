#include "library.h"
using namespace std;
// các biến được sử dụng lại nhiều lần
int countword;
int key;
Word W;


/*void welcome()

{
    cout<<"Ban muon dang ky hay dang nhap(DK:dang ky, DN:Dang nhap)"<<endl;
}*/
void option()
{
    cout<<"Ban muon lua chon option nao\n";
    cout<<"Tra tu(Tr),Tra Ngu Phap(NP),Xem Lich Su(LS),show(Sh)\n"; 
}
void readfile(ifstream& in,Vector_User& v)
{
    string s="1",init;
    int i=0;
    User u(i,init,init);
    //int k=0;
    while(true){             // kiểm tra xem luồng stream trong file in đã hết chưa
        //k++;
        getline(in,s);
        if(s=="")break;
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
void showinfo(Vector_User& v)
{
    int k=v.getSize();
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

void sign_up(Vector_User& UserList, ofstream& write, int& id)
{
    string name, password, confirm_password; 

    cout << "Nhap ten dang nhap: ";
    getline(cin, name);
    cout << "Nhap mat khau: ";
    getline(cin, password);
    cout << "Nhap lai mat khau: ";
    getline(cin, confirm_password);
    if (password == confirm_password) {
        ++id;
        write << name << "," << password << "," << id << "\n"; 

        write.flush(); // Đảm bảo ghi ngay vào file

        User u(id, name, password); // Tạo user mới
        UserList.pb(u);

        cout << "Dang ky thanh cong!" << endl;

    } else {
        cout << "Mat khau khong khop. Vui long thu lai." << endl;
    }
    pauseScreen(); // Thêm tạm dừng để người dùng đọc thông báo
}

void log_out()
{
    cout<<"Ban co muon thoat khoi web ko(e:Exit)\n";
}

void login(User*& currentUser, Vector_User& UserList, int& id) {
    string username, password;
    cout << "--- DANG NHAP ---\n";
    cout << "Nhap ten dang nhap: ";
    getline(cin, username);
    cout << "Nhap mat khau: ";
    getline(cin, password);

    User NewUser(id,username, password);
    
    for (int i = 0; i < UserList.getSize(); i++){
        if (UserList[i].getUsername() == username && UserList[i].getPassword() == password) {
            currentUser = &UserList[i];
            break;
        }
    }   

    if (currentUser != nullptr) {
        cout << "\nDang nhap thanh cong! Chao mung tro lai, " << currentUser->getUsername() << "!" << endl;
    } else{
        cout << "\nTen dang nhap hoac mat khau khong dung." << endl;
    }
    pauseScreen();
}

void LoginMenu(User*& currentUser, Vector_User& UserList, int& id,ofstream& write) {
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
        getline(cin, input);
        
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

void MainMenu(User*& currentUser, HashTable_Word& Dictionary) {
    int choice = 0;
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
                {
                    string word;
                    cout << "Hay ghi tu ban muon tra: ";
                    getline(cin, word);
                    Search(Dictionary, word, currentUser);
                    pauseScreen();
                }
                break;
            case 2:
                // Thêm chức năng tra ngữ pháp ở đây
                break;
            case 3:
                viewHistory(currentUser);
                pauseScreen();
                break;
            case 4:
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
        Vector_String& historyList = currentUser->getHistory(); // Lấy danh sách lịch sử
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
void Search(HashTable_Word& Dictionary, string& word, User*& currentUser)
{
    countword = 0;
    for(int i=0;i<word.size();i++){
        word[i]= tolower(word[i]);
        countword += (i+1)* ((int)word[i]);         // chuyển đổi dạng string thành tổng các chữ số 
    }                                               // theo công thức 

    key = Dictionary.getkey(countword);             // lấy key để hash
    for(int i=0;i<Dictionary[key].getsize();i++){
        if(Dictionary[key][i].getidword() == countword && word == Dictionary[key][i].GetName()){  
            //cout<<"id find:"<<countword<<endl;          
            Dictionary[key][i].GetInfoWord();
            currentUser->addHistory(word); // Lưu từ tìm kiếm vào lịch sử của User hiện tại              
        }
    }
    cout<<"Không có từ bạn tìm kiếm ở trong từ điển này\n";
}

void readvocal(HashTable_Word& Dictionary,ifstream& vocabulary)
{
    int i;
    string s;
    while(true){
        getline(vocabulary,s);
        if(s=="")break;
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

void luu_vocalbulary(HashTable_Word& Dictionary, ofstream& write){
    for(int i=0; i <Dictionary.getcapacity();i++){
        for(int j=0;j<Dictionary[i].getsize();j++){
            write<<Dictionary[i][j].GetName()<<",";
            write<<Dictionary[i][j].GetType()<<",";
            write<<Dictionary[i][j].GetMean()<<",";
            write<<Dictionary[i][j].GetExample()<<",";
            write<<Dictionary[i][j].GetPronounce()<<"\n";
        }
    }
}
