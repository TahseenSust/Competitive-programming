#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int n;
ll mat[80][80];
bool vis[80][80];

ll dp[80][80][7][4];

ll solve(int i,int j,int k,int dir)
{
    if(i==n-1 && j==n-1){
        if(mat[i][j]<0 && k==0) return -100000000000000000;
        return mat[i][j];
    }

    ll &re=dp[i][j][k][dir];

    if(re!=-1){
        return re;
    }

    re=-(1ll)<<60;

    if(dir==2 || dir==1){
        if(j+1<n){
            if(mat[i][j]<0){
                if(k>0)
                    re=max(re,solve(i,j+1,k-1,2)+mat[i][j]);
            }else{
                re=max(re,solve(i,j+1,k,2)+mat[i][j]);
            }
        }
        if(i+1<n){
            if(mat[i][j]<0){
                if(k>0)
                    re=max(re,solve(i+1,j,k-1,1)+mat[i][j]);
            }else{
                re=max(re,solve(i+1,j,k,1)+mat[i][j]);
            }
        }
    }

    if(dir==0 || dir==1){
        if(j-1>=0){
            if(mat[i][j]<0){
                if(k>0)
                    re=max(re,solve(i,j-1,k-1,0)+mat[i][j]);
            }else{
                re=max(re,solve(i,j-1,k,0)+mat[i][j]);
            }
        }
        if(i+1<n){
            if(mat[i][j]<0){
                if(k>0)
                    re=max(re,solve(i+1,j,k-1,1)+mat[i][j]);
            }else{
                re=max(re,solve(i+1,j,k,1)+mat[i][j]);
            }
        }
    }
    return re;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int k;
    int tc=1;
    while(cin>>n>>k){
        if(n==0 && k==0) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }

        memset(dp,-1,sizeof dp);

        ll ans=solve(0,0,k,2);

        if(ans<-(1ll)<<40){
            printf("Case %d: impossible\n",tc++);
        }else{
            printf("Case %d: %lld\n",tc++,ans);
        }

    }
}
