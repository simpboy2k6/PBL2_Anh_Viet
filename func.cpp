#include "library.h"
using namespace std;
// các biến được sử dụng lại nhiều lần
int countword;
int key;
Word W;

void welcome()

{
    cout<<"Ban muon dang ky hay dang nhap(DK:dang ky, DN:Dang nhap)"<<endl;
}

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
void readfile( ifstream& in,Vector_User& v)
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

    int k=v.getsize();
    for(int i=0;i<k;i++)
    {
        v[i].showinfo();
    }
}


void Search(HashTable_Word& Dictionary,string& word)
{
    countword = 0;
    for(int i=0;i<word.size();i++){
        word[i]= tolower(word[i]);
        countword += (i+1)* ((int)word[i]);         // chuyển đổi dạng string thành tổng các chữ số 
    }                                               // theo công thức 

    key = Dictionary.getkey(countword);             // lấy key để hash
    for(int i=0;i<Dictionary[key].getsize();i++){
        if(Dictionary[key][i].getidword() == countword){            
            Dictionary[key][i].GetInfoWord();           
            return;
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