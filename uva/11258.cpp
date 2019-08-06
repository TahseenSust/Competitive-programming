#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1000];

string str;


ll solve(int i)
{
    if(i==str.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    ll re=0;
    if(str[i]=='0'){
        re=solve(i+1);
    }else{
        ll x=0;
        re=x;
        for(int j=i;j<str.size();j++){
            x=x*10+(str[j]-'0');
            if(x>INT_MAX){
                break;
            }
            re=max(re,x+solve(j+1));
        }
    }
    return dp[i]=re;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        memset(dp,-1,sizeof dp);
        cout<<solve(0)<<endl;
    }
}
