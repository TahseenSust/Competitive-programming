#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool vis[110][110];
int n,m;
string str[150];

int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

void flood_fill(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m){
        return;
    }
    if(vis[x][y] || str[x][y]=='*'){
        return;
    }
    vis[x][y]=1;
    for(int i=0;i<8;i++){
        flood_fill(x+dx[i],y+dy[i]);
    }
}

int main()
{
    while(cin>>n>>m){
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            cin>>str[i];
        }
        int ans=0;
        memset(vis,false,sizeof vis);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(str[i][j]=='@' && vis[i][j]==0){
                    ans++;;
                    flood_fill(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }
}
