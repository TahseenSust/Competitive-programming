#include<bits/stdc++.h>
using namespace std;

int n,m,mat[12][102];
int dp[12][102];
int dx[]={-1,0,+1};
int solve(int r,int c)
{
    if(c==m-1){
        return dp[r][c]=mat[r][c];
    }
    int &re=dp[r][c];
    if(re!=-1){
        return re;
    }
    re=INT_MAX;
    for(int i=0;i<3;i++){
        int tr=r+dx[i];
        if(tr<0){
            tr=n-1;
        }else if(tr>=n){
            tr=0;
        }
        re=min(re,solve(tr,c+1)+mat[r][c]);
    }
    return re;
}


void path(int r,int c)
{
    if(c==m-1){
        return;
    }
    int re=INT_MAX,idx;
    for(int i=0;i<3;i++){
        int tr=r+dx[i];
        if(tr<0){
            tr=n-1;
        }else if(tr>=n){
            tr=0;
        }
        if(dp[tr][c+1]+mat[r][c]<re){
            re=dp[tr][c+1]+mat[r][c];
            idx=tr;
        }else if(dp[tr][c+1]+mat[r][c]==re && idx>tr){
            idx=tr;
        }
    }
    cout<<' '<<idx+1;
    path(idx,c+1);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(cin>>n>>m){

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }

        int ans=INT_MAX,idx;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            int tmp=solve(i,0);
            if(tmp<ans){
                ans=tmp;
                idx=i;
            }
        }
        cout<<idx+1;
        path(idx,0);
        cout<<endl;
        cout<<ans<<endl;
    }
}
