#include<iostream>
using namespace std;

int main(){
    string s1,s2;
    int l1= s1.size(), l2 = s2.size();
    int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=l2;i++){
        dp[0][i]=i;
    }
    int replace,dele,append;
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            int cost = (s1[i-1] == s2[j-1])? 0:1;
            replace = dp[i-1][j-1] + cost;
            dele = dp[i-i][j] +1;
            append = dp[i][j-1] +1;

            int nho =min(replace,dele);
            nho =min(nho,append);
            dp[i][j]= nho;
        }
    }
    
    
}