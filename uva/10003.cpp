#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll le,n,cut[55];
ll dp[1005][1005];

ll solve(int l,int r)
{
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    ll re=INT_MAX;

    for(int i=0;i<n;i++){
        if(cut[i]>l && cut[i]<r){
            re=min(re,r-l+solve(l,cut[i])+solve(cut[i],r));
        }
    }
    if(re==INT_MAX){
        re=0;
    }
    return dp[l][r]=re;
}
int main()
{

    while(cin>>le && le){
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>cut[i];
        }
        memset(dp,-1,sizeof dp);
        cout<<"The minimum cutting is "<<solve(0,le)<<"."<<endl;
    }

}
