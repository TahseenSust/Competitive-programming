#include<bits/stdc++.h>
using namespace std;
#define MAX 110
int n1,n2;
int a[MAX],b[MAX];
int dp[MAX][MAX];
bool visit[MAX][MAX];
int LCS(int i,int j)
{
    if(i==n1||j==n2){
        return 0;
    }
    if(visit[i][j]){
        return dp[i][j];
    }
    int ans=0;
    if(a[i]==b[j]){
        ans=1+LCS(i+1,j+1);
    }else{
        ans=max(LCS(i+1,j),LCS(i,j+1));
    }
    visit[i][j]=true;
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    int cn=1;
    while(cin>>n1>>n2 && n1 && n2){
        for(int i=0;i<n1;i++){
            cin>>a[i];
        }
        for(int i=0;i<n2;i++){
            cin>>b[i];
        }
        memset(visit,false,sizeof(visit));
        int ans=LCS(0,0);
        printf("Twin Towers #%d\n",cn++);
        printf("Number of Tiles : %d\n\n",ans);
    }
}
