#include <bits/stdc++.h>
using namespace std;
int coin[]={50,25,10,5,1};
int make;
int dp[10][8000];
int call(int i,int amount)
{
    if(i>=5){
        if(amount==make){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int re1=0,re2=0;
    if(amount+coin[i]<=make){
        re1=call(i,amount+coin[i]);
    }
    re2=call(i+1,amount);
    return dp[i][amount]=re1+re2;
}
int main()
{
    while(cin>>make){
        memset(dp,-1,sizeof(dp));
        cout<<call(0,0)<<endl;
    }

}


