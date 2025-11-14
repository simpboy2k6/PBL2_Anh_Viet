#include "library.h"
using namespace std;
// các biến được sử dụng lại nhiều lần
int countword,value;
int key;
Word W;
string HistoryDir = "User_history/";
string UpdateHistoryDir = "data/update.txt";
ifstream CurrentUserHistoryDirRead;
ofstream CurrentUserHistoryDirWrite;
ifstream RequestRead,UpDateHistoryRead;
ofstream RequestWrite,UpDateHistoryWrite;
string RequestDir = "data/request.txt";
Vector<string> Request;
auto now = chrono::system_clock::now();
time_t CurrentTime;
Vector<string> UpdateHistory;

void option()
{
    cout<<"Ban muon lua chon option nao\n";
    cout<<"Tra tu(Tr),Tra Ngu Phap(NP),Xem Lich Su(LS),show(Sh)\n"; 
}
void readfile(ifstream& in,Vector<User>& v)
{
    string s;
    int i=0;
    
    while(getline(in,s)){             // kiểm tra xem luồng stream trong file in đã hết chưa
        i=0;
        User u;
        stringstream ss(s);
        
        while(getline(ss,s,',')){
            //cout<<s<<" ";
            if(i==0){
                u.SetUserName(s);
            }else if(i==1){
                u.SetUserPassword(s);
            }else u.SetUserid(stoi(s));
            i++;
            //cout<<i<<" ";
        }
        //cout<<endl;
        v.pb(u);
    }
}
void ReadRequest(){
    string s;
    RequestRead.open(RequestDir);
    while(getline(RequestRead,s)){
        Request.pb(s);
    }
    RequestRead.close();
}
void ShowRequest(){
    for(int i=0;i<Request.getsize();i++){
        cout<<"["<<i+1<<"]"<<Request[i]<<"\n";
    }

}
void ReadUpdateHistory(){
    UpDateHistoryRead.open(UpdateHistoryDir);
    string s;
    while(getline(UpDateHistoryRead,s)){
        UpdateHistory.pb(s);
    }
    
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
    ReadRequest();
    ReadUpdateHistory();
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

void MainMenu(User*& currentUser, HashTable<Word*>& Dictionary, Vector<Grammar>& gList) {
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
        cout << "[4] Dang xuat\n";
        cout << "[5] Admin mode\n\n";
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

                RequestWrite.open(RequestDir);
                for(int i=0;i<Request.getsize();i++){
                    RequestWrite << Request[i] <<"\n";          // lưu yêu cầu người dùng khi thoát ứng dụng
                }
                RequestWrite.close(); 
                Request.Erase_Vector();
                
                UpDateHistoryWrite.open(UpdateHistoryDir);
                for(int i=0;i<UpdateHistory.getsize();i++){
                    UpDateHistoryWrite << UpdateHistory[i] << "\n"; // lưu lịch sử cập nhật từ điển của Admin khi thoát ứng dụng
                }
                UpDateHistoryWrite.close();
                UpdateHistory.Erase_Vector();

                currentUser = nullptr;
                cout << "Dang xuat thanh cong!" << endl;
                pauseScreen();
                return;
            case 5: 
                AdminMode(currentUser,Dictionary,gList);
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
                pauseScreen();
        }
    }
}
void AdminMode(User*& currentUser, HashTable<Word*>& Dictionary, Vector<Grammar>& gList){
    cout<<"Hãy nhập mật khẩu của Admin Mode:";
    string s;
    getline(cin,s);
    if(s!="Admin is here"){
        cout<<"Mật khẩu không đúng\n";
        pauseScreen();
        return;
    }else{
        
        while (true) {
            clearScreen();
            cout << "+----------------------------------------+\n";
            cout << "|                                        |\n";
            cout << "|             CHE DO ADMIN               |\n";
            cout << "|                                        |\n";
            
            cout << "|";
            string welcome_text = "Welcome, Admin"; // 14 ky tu
            int internal_width = 38;
            int padding = internal_width - welcome_text.length() - 2; // -2 cho "  |"
            
            for (int i = 0; i < padding; i++) {
                cout << " ";
            }
            cout << welcome_text << "    |\n";
            cout << "+----------------------------------------+\n\n";

            // Các lựa chọn của Admin
            cout << "[1] Xem yeu cau them tu\n";
            cout << "[2] Chinh sua tu dien\n";
            cout << "[3] Them tu\n";
            cout << "[4] Xem lich su cap nhat\n";
            cout << "[5] Thoat che do Admin\n\n";
            cout << "Vui long chon: ";

            string input;
            int choice = 0;
            getline(cin, input);

            // Cách đọc input an toàn hơn, tránh lỗi
            stringstream ss(input);
            ss >> choice; // Thử đọc một số từ input

            switch (choice) {
                case 1:
                    clearScreen();
                    CheckRequest();
                    pauseScreen();
                    break;
                case 2:
                    clearScreen();
                    ModifiedDictionary(Dictionary);
                    pauseScreen();
                    break;
                case 3:
                    clearScreen();
                    AddNewWord(Dictionary);
                    pauseScreen();
                    break;
                case 4:
                    clearScreen();
                    ShowUpdateHistory();
                    pauseScreen();
                    break;
                case 5:
                    pauseScreen();
                    return; 
                default:
                    cout << "\nLua chon khong hop le. Vui long thu lai." << endl;
                    pauseScreen();
            }
        }
    }
}
void ShowUpdateHistory(){
    cout << "===  XEM LICH SU CAP NHAT TU DIEN ===\n";
    for(int i=0;i<UpdateHistory.getsize();i++){
        cout<<UpdateHistory[i]<<"\n";
    }
}
void ModifiedDictionary(HashTable<Word*>& Dictionary){
    while(true){
        string word;
        Vector<int> v_index;
        cout << "=== CHINH SUA TU DIEN ===\n";
        cout<<"Nhập từ bạn muốn chỉnh sửa tại đây(0: Thoát):";
        getline(cin,word);
        if(word == "0")break;

        countword = 0;value =0;
        for(int i=0;i<word.size();i++){
            word[i]= tolower(word[i]);
            value += (i+1)* ((int)word[i]);        
        }                                           
        key = Dictionary.getkey(value);            
        for(int i=0;i<Dictionary[key].getsize();i++){
            if(Dictionary[key][i]->GetId() == value && word == Dictionary[key][i]->GetName()){  
                countword++;                                // check xem đã có từ đó trong Dictionaty chưa
                v_index.pb(i);
            }
        }
        if(countword == 0){
            cout<<"Không có từ này trong từ điển";
            pauseScreen();
        }else{
            int index;
            cout<<"Đây là các từ tương ứng trong từ điển:\n";
            for(int i=0;i<v_index.getsize();i++){
                cout<<"["<<i+1<<"]";
                Dictionary[key][v_index[i]]->GetInfoWord();
            }
            cout<<"Bạn muốn chỉnh sửa từ nào(0: không chọn):";
            cin>>index;
            if(index!=0){
                index = v_index[index-1];
                clearScreen();
                ModifiedWord(Dictionary,key,index);
                continue;
            }

        }
        clearScreen();
    }

}
void ModifiedWord(HashTable<Word*>& Dictionary,int key, int& index){
    string choice;string update;
    if(Dictionary[key][index]->GetType()=="verb"){
        Verb *DongTu = static_cast<Verb*>(Dictionary[key][index]);
        while(true){
            DongTu->GetInfoWord();
            cout<<"[1]:Thay đổi nghĩa\n";
            cout<<"[2]:Thay đổi ví dụ\n";
            cout<<"[3]:Thay đổi cách phát âm\n";
            cout<<"[4]:Xóa từ này\n";
            cout<<"[5]:Thay đổi V2\n";                  // chỉnh sửa đối với Động Từ
            cout<<"[6]:Thay đổi V3\n";
            cout<<"Bạn muốn lựa chọn cái nào (0: Thoát):";
            getline(cin,choice);
            
            if(choice == "4"){
                now = chrono::system_clock::now();
                CurrentTime = chrono::system_clock::to_time_t(now);
                UpdateHistory.pb("Delete word: "+ Dictionary[key][index]->GetName()+" | Time :"+ ctime(&CurrentTime));
                Dictionary[key].Erase(index);
                cout<<"Đã xóa thành công\n";
                pauseScreen();
                clearScreen();
                break;
            }else if(choice == "6"){
                cout<<"Nhập V3 mới:";
                getline(cin,update);
                DongTu->SetV3(update);
            }else if(choice == "5"){
                cout<<"Nhập V2 mới:";
                getline(cin,update);
                DongTu->SetV2(update);
            }else if(choice == "2"){
                cout<<"Nhập ví dụ mới:";
                getline(cin,update);
                DongTu->SetExample(update);
            }else if(choice == "3"){
                cout<<"Nhập cách phát âm mới:";
                getline(cin,update);
                DongTu->SetPronounce(update);
            }else if(choice == "1"){
                cout<<"Nhập nghĩa mới:";
                getline(cin,update);
                DongTu->SetMean(update);
            }else if(choice == "0" ){
                clearScreen();
                break;
            }else{
                cout<<"Lựa chọn không hợp lệ\n";
            }
            clearScreen();
        }
    }else if(Dictionary[key][index]->GetType()=="noun"){
        Noun *DanhTu = static_cast<Noun*>(Dictionary[key][index]);
        while(true){
            DanhTu->GetInfoWord();
            cout<<"[1]:Thay đổi nghĩa\n";
            cout<<"[2]:Thay đổi ví dụ\n";
            cout<<"[3]:Thay đổi cách phát âm\n";            // chỉnh sửa đối với Danh Từ
            cout<<"[4]:Xóa từ này\n";
            cout<<"[5]:Thay đổi thông tin có đếm được không?\n";
            cout<<"[6]:Thay đổi dạng số nhiều\n";
            cout<<"Bạn muốn lựa chọn cái nào (0: Thoát):";
            getline(cin,choice);
            
            if(choice == "4"){
                now = chrono::system_clock::now();
                CurrentTime = chrono::system_clock::to_time_t(now);
                UpdateHistory.pb("Delete word: "+ Dictionary[key][index]->GetName()+" | Time :"+ ctime(&CurrentTime));
                Dictionary[key].Erase(index);
                cout<<"Đã xóa thành công\n";
                pauseScreen();
                clearScreen();
                break;
            }else if(choice == "6"){
                cout<<"Nhập dạng số nhiều mới:";
                getline(cin,update);
                DanhTu->SetSoNhieu(update);
            }else if(choice == "5"){
                cout<<"Nhập thông tin có đếm được không(đếm được hoặc không đếm được):";
                getline(cin,update);
                DanhTu->SetDemDuoc(update);
            }else if(choice == "2"){
                cout<<"Nhập ví dụ mới:";
                getline(cin,update);    
                DanhTu->SetExample(update);
            }else if(choice == "3"){
                cout<<"Nhập cách phát âm mới:";
                getline(cin,update);
                DanhTu->SetPronounce(update);
            }else if(choice == "1"){
                cout<<"Nhập nghĩa mới:";
                getline(cin,update);
                DanhTu->SetMean(update);
            }else if(choice == "0" ){
                clearScreen();
                break;
            }else{
                cout<<"Lựa chọn không hợp lệ\n";
            }
            clearScreen();
        }
    }else if(Dictionary[key][index]->GetType()=="adjective"){
        Adj *TinhTu = static_cast<Adj*>(Dictionary[key][index]);
        while(true){
            TinhTu->GetInfoWord();
            cout<<"[1]:Thay đổi nghĩa\n";
            cout<<"[2]:Thay đổi ví dụ\n";
            cout<<"[3]:Thay đổi cách phát âm\n";                // chỉnh sửa đối với Tính Từ
            cout<<"[4]:Xóa từ này\n";
            cout<<"[5]:Thay đổi dạng so sánh hơn\n";
            cout<<"[6]:Thay đổi dạng so sánh Nhất\n";
            cout<<"Bạn muốn lựa chọn cái nào (0: Thoát):";
            getline(cin,choice);
            
            if(choice == "4"){
                now = chrono::system_clock::now();
                CurrentTime = chrono::system_clock::to_time_t(now);
                UpdateHistory.pb("Delete word: "+ Dictionary[key][index]->GetName()+" | Time :"+ ctime(&CurrentTime));
                Dictionary[key].Erase(index);
                cout<<"Đã xóa thành công\n";
                pauseScreen();
                clearScreen();
                break;
            }else if(choice == "6"){
                cout<<"Nhập dạng so sánh nhất mới:";
                getline(cin,update);
                TinhTu->SetSoSanhNhat(update);
            }else if(choice == "5"){
                cout<<"Nhập dạng so sánh hơn mới:";
                getline(cin,update);
                TinhTu->SetSoSanhHon(update);
            }else if(choice == "2"){
                cout<<"Nhập ví dụ mới:";
                getline(cin,update);    
                TinhTu->SetExample(update);
            }else if(choice == "3"){
                cout<<"Nhập cách phát âm mới:";
                getline(cin,update);
                TinhTu->SetPronounce(update);
            }else if(choice == "1"){
                cout<<"Nhập nghĩa mới:";
                getline(cin,update);
                TinhTu->SetMean(update);
            }else if(choice == "0" ){
                clearScreen();
                break;
            }else{
                cout<<"Lựa chọn không hợp lệ\n";
            }
            clearScreen();
        }
    }
}

void CheckRequest(){
    int index;
    while(true){
        cout << "=== XEM YEU CAU THEM TU ===\n";
        ShowRequest();
        cout<<"Bạn có muốn xóa yêu cầu nào không(0: Thoát):";
        cin>>index;
        if(index==0)break;
        index--;
        Request.Erase(index);
        cout<<"Đã xóa thành công";
        pauseScreen();
        clearScreen();
    }
}
// Chức năng thêm từ của Admin Mode
void AddNewWord(HashTable<Word*>& Dictionary){
    string word,type,example,pronounce,mean;
    while(true){
        cout << "=== THEM TU MOI ===\n";
        cout<<"Nhập từ muốn thêm vào(0: Thoát):";
        getline(cin,word);
        if(word == "0")break;
        countword = 0;value =0;
        for(int i=0;i<word.size();i++){
            word[i]= tolower(word[i]);
            value += (i+1)* ((int)word[i]);        
        }                                           
        key = Dictionary.getkey(value);            
        for(int i=0;i<Dictionary[key].getsize();i++){
            if(Dictionary[key][i]->GetId() == value && word == Dictionary[key][i]->GetName()){  
                countword++;                                // check xem đã có từ đó trong Dictionaty chưa
            }
        }
        if(countword !=0){
            cout<<"Đã có từ này trong từ điển!\n";
            pauseScreen();
        }else{
            cout <<"Nhập nghĩa của từ:";
            getline(cin,mean);
            cout <<"Nhập loại của từ(chỉ một loại):";
            getline(cin,type);
            cout <<"Nhập một câu ví dụ:";
            getline(cin,example);
            cout <<"Nhập cách phát âm của từ đó:";
            getline(cin,pronounce);
            if(type == "verb"){
                Verb *DongTu = new Verb();
                DongTu->SetName(word);
                DongTu->SetMean(mean);
                DongTu->SetType(type);
                DongTu->SetExample(example);
                DongTu->SetPronounce(pronounce);
                cout <<"Nhập V2 của từ đó:";
                string V2,V3;
                getline(cin,V2);
                cout <<"Nhập V3 của từ đó:";
                getline(cin,V3);
                DongTu->SetV2(V2);
                DongTu->SetV3(V3);
                Dictionary.hash(DongTu,Dictionary.getkey(DongTu->GetId()));
            }else if(type == "noun"){
                Noun *DanhTu = new Noun();
                DanhTu->SetName(word);
                DanhTu->SetMean(mean);
                DanhTu->SetType(type);
                DanhTu->SetExample(example);
                DanhTu->SetPronounce(pronounce);
                cout <<"Từ đó có đếm được không( đếm được hoặc không đếm được):";
                string demduoc,sonhieu;
                getline(cin,demduoc);
                cout <<"Nhập dạng số nhiều của từ đó:";
                getline(cin,sonhieu);
                DanhTu->SetDemDuoc(demduoc);
                DanhTu->SetSoNhieu(sonhieu);
                Dictionary.hash(DanhTu,Dictionary.getkey(DanhTu->GetId()));
            }else if(type == "adjective"){
                Adj *TinhTu = new Adj();
                TinhTu->SetName(word);
                TinhTu->SetMean(mean);
                TinhTu->SetType(type);
                TinhTu->SetExample(example);
                TinhTu->SetPronounce(pronounce);
                cout <<"Nhập dạng so sánh hơn của từ đó:";
                string ssh,ssn;
                getline(cin,ssh);
                cout <<"Nhập dạng so sánh nhất của từ đó:";
                getline(cin,ssn);
                TinhTu->SetSoSanhHon(ssh);
                TinhTu->SetSoSanhNhat(ssn);
                Dictionary.hash(TinhTu,Dictionary.getkey(TinhTu->GetId()));
            }
            cout<<"Đã thêm từ thành công\n";
            now = chrono::system_clock::now();
            CurrentTime = chrono::system_clock::to_time_t(now);
            UpdateHistory.pb("Add word: "+ word+" | Time :"+ ctime(&CurrentTime));
            pauseScreen();
            
        }
        clearScreen();
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
void Search(HashTable<Word*>& Dictionary, string& word, User*& currentUser)
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
    now = chrono::system_clock::now();
    CurrentTime = chrono::system_clock::to_time_t(now);
    for(int i=0;i<Dictionary[key].getsize();i++){
        if(Dictionary[key][i]->GetId() == value && word == Dictionary[key][i]->GetName()){  
            if(Dictionary[key][i]->GetType() == "verb"){
                Verb *DongTu = static_cast<Verb*>(Dictionary[key][i]);
                DongTu->GetInfoWord();
            }else if(Dictionary[key][i]->GetType() == "noun"){
                Noun *DanhTu = static_cast<Noun*>(Dictionary[key][i]);      // in ra tùy vào kiểu 
                DanhTu->GetInfoWord();
            }else if(Dictionary[key][i]->GetType() == "adjective"){
                Adj *TinhTu = static_cast<Adj*>(Dictionary[key][i]);
                TinhTu->GetInfoWord();
            }
            if(countword==0){
                currentUser->addHistory(word + " | Time : "+ ctime(&CurrentTime)); // Lưu từ tìm kiếm vào lịch sử của User hiện tại

            }
            countword++;         
        }
    }
    
    if(countword==0){
        cout<<"Không có từ bạn tìm kiếm ở trong từ điển này\n";
        cout<<"Bạn có muốn yêu cầu thêm từ này vào không(Y:Yes;N:No)";
        string s;cin>>s;
        if(s=="Y"){
            Request.pb(word);
        }
    }
}

void readvocal(HashTable<Word*>& Dictionary,ifstream& vocabulary)
{
    string line,token,loai,name,example,pronouce,extra1,extra2,mean;
    while(getline(vocabulary,line)){
        if (line == "") continue;
        cout << "s:" << line << "\n";
        stringstream ss(line);
        int i=0;

        Word* W = nullptr;
        Verb* dongtu = nullptr;
        Noun* danhtu = nullptr;
        Adj* tinhtu = nullptr;

        while(getline(ss,token,',')){
            if(i==0){

            }else if(i==1){
                name = token;
            }else if(i==2){
                loai = token;
            }else if(i==3){
                mean = token;
            }else if(i==4){
                example = token;
            }else if(i==5){
                pronouce = token;
            }else if(i==6){
                extra1 = token;
            }else if(i==7){
                extra2 = token;
            }
            i++;
        }

        if(loai == "verb"){
            dongtu = new Verb();
            W = dongtu;
            W->SetName(name);
            W->SetType(loai);
            W->SetExample(example);
            W->SetMean(mean);
            W->SetPronounce(pronouce);
            dongtu->SetV2(extra1);
            dongtu->SetV3(extra2);
        }else if(loai == "noun"){
            danhtu = new Noun();
            W = danhtu;
            W->SetName(name);
            W->SetType(loai);
            W->SetExample(example);
            W->SetMean(mean);
            W->SetPronounce(pronouce);
            danhtu->SetDemDuoc(extra1);
            danhtu->SetSoNhieu(extra2);
        }else if( loai == "adjective"){
            tinhtu = new Adj();
            W = tinhtu;
            W->SetName(name);
            W->SetType(loai);
            W->SetExample(example);
            W->SetMean(mean);
            W->SetPronounce(pronouce);
            tinhtu->SetSoSanhHon(extra1);
            tinhtu->SetSoSanhNhat(extra2);
        }
        Dictionary.hash(W,Dictionary.getkey(W->GetId()));
    }
    cout << "exit\n";
    
}
void luu_vocalbulary(HashTable<Word*>& Dictionary, ofstream& write){
    for(int i=0; i <Dictionary.getcapacity();i++){
        for(int j=0;j<Dictionary[i].getsize();j++){
            write<<i<<",";
            write<<Dictionary[i][j]->GetName()<<",";
            write<<Dictionary[i][j]->GetType()<<",";
            write<<Dictionary[i][j]->GetMean()<<",";
            write<<Dictionary[i][j]->GetExample()<<",";
            write<<Dictionary[i][j]->GetPronounce()<<",";
            if(Dictionary[i][j]->GetType() == "verb"){

                Verb *DongTu = static_cast<Verb*>(Dictionary[i][j]);
                write << DongTu->GetV2()<<","<<DongTu->GetV3()<<"\n";

            }else if(Dictionary[i][j]->GetType() == "noun"){

                Noun *DanhTu = static_cast<Noun*>(Dictionary[i][j]);
                write << DanhTu->GetDemDuoc()<<","<<DanhTu->GetSoNhieu()<<"\n";

            }else if(Dictionary[i][j]->GetType() == "adjective"){
                Adj *TinhTu = static_cast<Adj*>(Dictionary[i][j]);
                write << TinhTu->GetSoSanhHon()<<","<<TinhTu->GetSoSanhNhat()<<"\n";
            }
            delete Dictionary[i][j];
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
    Vector<int> tmp;
    int distance = INT_MAX,index_tmp,dem =1;
    for(int i=0;i<gList.getsize();i++){
        index_tmp = DistanceLevenshtein(keyword,gList[i].GetName());
        tmp.pb(index_tmp);      // dùng Distance Leveinstain để tìm số thao tác của từng chuỗi
        distance = min(distance, index_tmp);
    }
    now = chrono::system_clock::now();
    CurrentTime = chrono::system_clock::to_time_t(now);
    bool found = false;
    for (int i = 0; i < gList.getsize(); ++i) {
        string ruleName = gList[i].GetName();
        for(char &c : ruleName) { c = tolower(c); }
        if (ruleName.find(keyword) != string::npos) {
            gList[i].GetInfoRule(); // In thông tin nếu tìm thấy
            currentUser->addHistory(gList[i].GetName()+" | Time:"+ ctime(&CurrentTime));
            found = true;
        }
    }
    
    if (!found) {
        Vector<int> GoiY;
        cout << "Khong tim thay quy tac ngu phap phu hop.\n";
        cout << "Cac Ngu Phap goi y:\n";
        for(int i=0;i<tmp.getsize();i++){
            if(tmp[i] == distance){
                GoiY.pb(i);
                cout<<"["<<dem++<<"]:";
                cout<<gList[i].GetName()<<"\n";
            }
        }
        int choice;
        cout<<"Hay lua chon Ngu Phap ban muon:";cin>>choice;
        if(choice>0 && choice <=dem){
            gList[choice-1].GetInfoRule();
            currentUser->addHistory(gList[choice-1].GetName()+" | Time:"+ ctime(&CurrentTime));
        }
        pauseScreen();
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

void SearchWord(HashTable<Word*>& Dictionary, User*& currentUser)
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

int DistanceLevenshtein(const std::string& s1,const std::string& s2){
    int l1= s1.size(), l2 = s2.size();
    int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++){
        dp[i][0]=i;             //đếm thao tác để ""  thành s1[1..i]
    }
    for(int i=0;i<=l2;i++){
        dp[0][i]=i;             // đếm thao tác để ""  thành s2[1..i]
    }
    int replace,dele,append;
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            int cost = (s1[i-1] == s2[j-1])? 0:1;

            replace = dp[i-1][j-1] + cost;  // thao tác thay
            dele = dp[i-i][j] +1;           // thao tác xóa
            append = dp[i][j-1] +1;         // thao tác chèn thêm

            int nho =min(replace,dele);
            nho =min(nho,append);
            dp[i][j]= nho;
        }
    }
    return dp[l1][l2];
}