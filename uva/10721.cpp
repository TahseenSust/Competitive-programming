#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k,m;
ll dp[53][53][53];

ll solve(int p,int q,int m)
{
    if(p==0){
        return (q==0);
    }

    ll &re=dp[p][q][m];

    if(re!=-1) return re;

    re=0ll;

    for(int i=1;i<=m && p-i>=0 && q-1>=0;i++){
        re=re+solve(p-i,q-1,m);
    }

    return re;
}


int main()
{
    memset(dp,-1,sizeof dp);
    while(cin>>n>>k>>m){
        printf("%lld\n",solve(n,k,m));
    }
}
