#include "library.h"
using namespace std;

/*void welcome()

{
    cout<<"Ban muon dang ky hay dang nhap(DK:dang ky, DN:Dang nhap)"<<endl;
}*/

void sign_up(string& name, string& password)
{
    cout<<"Nhap ten:";
    getline(cin,name);
    cout<<"Nhap password:";
    getline(cin,password);
}

void log_out()
{
    cout<<"Ban co muon thoat khoi web ko(e:Exit)\n";
}

void option()
{
    cout<<"Ban muon lua chon option nao\n";
    cout<<"Tra tu(Tr),Tra Ngu Phap(NP),Xem Lich Su(LS),show(Sh)\n"; 
}
void readfile( ifstream& in,vector<User>& v)
{
    string s="1",init;
    int i=0;
    User u(i,init,init);
    //int k=0;
    while(in.eof()==false){             // kiểm tra xem luồng stream trong file in đã hết chưa
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
        v.push_back(u);
    }
    //cout<<"chay trong "<<k<<"lan"<<endl;
}
void showinfo(vector<User>& v)
{
    int k=v.size();
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

void login(User*& currentUser) {
    string username, password;
    cout << "--- DANG NHAP ---\n";
    cout << "Nhap ten dang nhap: ";
    getline(cin, username);
    cout << "Nhap mat khau: ";
    getline(cin, password);

    User NewUser(ID,username, password);
    
    for (const auto& NewUser : UserList) {
        if (NewUser.getUsername() == username && NewUser.getPassword() == password) {
            
            break;
        }
    }   

    if (currentUser != nullptr) {
        cout << "\nDang nhap thanh cong! Chao mung tro lai, " << currentUser->getUsername() << "!" << endl;
    } else {
        cout << "\nTen dang nhap hoac mat khau khong dung." << endl;
    }
    pauseScreen();
}

void LoginMenu(User*& currentUser) {
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
            case 1: login(); break;
            case 2: sign_up(); break;
            case 3: 
                cout << "Tam biet!" << endl;
                return; 
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
                pauseScreen();
        }
    }
}



