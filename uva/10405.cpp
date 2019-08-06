#include<bits/stdc++.h>
using namespace std;
#define MAX 1050
string a,b;
int dp[MAX][MAX];
bool visit[MAX][MAX];
int LCS(int i,int j)
{
    if(a[i]=='\0'||b[j]=='\0') return 0;
    if(visit[i][j]) return dp[i][j];
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
    //freopen("input.txt","r",stdin);
    while(getline(cin,a)){
        getline(cin,b);
        memset(visit,false,sizeof(visit));
        cout<<LCS(0,0)<<endl;
        a[0]='\0';
        b[0]='\0';
    }
}
