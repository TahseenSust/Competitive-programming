#include<bits/stdc++.h>
using namespace std;
#define max_N 1050
#define max_W 1050
int n,dp[max_N+1][max_W+1],weight[max_N+1],cost[max_N+1],CAP;
int func(int i,int w)
{
    if(i==n+1) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int p1=0,p2=0;
    if(w+weight[i]<=CAP){
        p1=cost[i]+func(i+1,w+weight[i]);
    }
    p2=func(i+1,w);
    dp[i][w]=max(p1,p2);
    return dp[i][w];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int g;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&cost[i],&weight[i]);
        }
        scanf("%d",&g);
        int ans=0;
        for(int i=0;i<g;i++){
            scanf("%d",&CAP);
            memset(dp,-1,sizeof(dp));
            int ret=func(1,0);
            ans+=ret;
        }
        printf("%d\n",ans);
    }
}
/*
4 10
1 120
4 280
3 150
4 200
*/

