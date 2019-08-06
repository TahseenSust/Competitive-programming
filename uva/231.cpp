#include<bits/stdc++.h>
using namespace std;
int val[1000000];
int dp[1000000],n,dir[1000000];
int LDS(int u)
{
    if(dp[u]!=-1){
        return dp[u];
    }
    int mx=0;
    for(int v=u+1;v<n;v++){
        if(val[v]<=val[u]){
            if(LDS(v)>mx){
                mx=LDS(v);
                dir[u]=v;
            }
        }
    }
    dp[u]=mx+1;
    return dp[u];
}
void p(int u)
{
    while(dir[u]!=-1){
        printf("%d --- %d\n",u,dir[u]);
        u=dir[u];
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int mx,x,ans,cn=1;
    while(cin>>x&&x!=-1){
        val[0]=INT_MAX;
        n=1;
        val[n++]=x;
        while(cin>>x&&x!=-1){
            val[n++]=x;
        }
        mx=0,ans=0;
        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));
        for(int i=1;i<n;i++){
            mx=LDS(i);
            //cout<<mx<<endl;
            if(ans<mx){
                ans=mx;
                x=i;
            }
        }
        //p(x);
        if(cn!=1) printf("\n");
        printf("Test #%d:\n",cn++);
        printf("  maximum possible interceptions: %d\n",ans);
    }
}
/**
389
207
155
300
299
170
158
65
-1
23
34
21
-1
-1
*/
