#include<bits/stdc++.h>
using namespace std;


int dp[10002];

void solve()
{
    memset(dp,31,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=10000;i++){
        for(int j=i*i;j<=10000;j++){
            dp[j]=min(dp[j],dp[j-i*i]+1);
        }
    }
}



int main()
{
    solve();
    int t,n;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
}
