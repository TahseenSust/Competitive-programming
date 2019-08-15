#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1005][1005];

int solve(int n,int mv)
{
    if(n==0) return 0;

    int &re=dp[n][mv];

    if(re!=-1) return re;

    for(int i=1;i<=mv;i++)
    {
        if(n-i>=0 && solve(n-i,min(n-i,i*2))==0){
            return re=1;
        }
    }

    return re=0;

}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    int t,n;

    int state[1005];

    memset(dp,-1,sizeof dp);

    for(int i=2;i<=1000;i++)
    {
        state[i]=solve(i,i-1);
    }


    while(scanf("%d",&n) && n){
        if(state[n]){
            printf("Alicia\n");
        }else{
            printf("Roberto\n");
        }

    }

}
