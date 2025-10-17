#include "library.h"
using namespace std;
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


