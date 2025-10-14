#include<bits/stdc++.h>
using namespace std;

int main(){
    int *arr = new int[4];
    int *tmp = arr;
    for(int i=0;i<4;i++){
        cin>>*(arr+i);
    }
    for(int i=0;i<4;i++){
        cout<<*(arr+i)<<" ";

    }
    cout<<endl;
    delete[] arr;
    arr = new int[5];
    arr = tmp;
    *(arr + 4) = 10;
    for(int i=0;i<5;i++){
        cout<<*(arr+i)<<" ";
    }
}