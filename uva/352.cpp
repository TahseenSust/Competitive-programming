#include <bits/stdc++.h>
using namespace std;
string str[30];
bool vis[30][30];


int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

void flood_fill(int x,int y,int n)
{
    if(x<0 || y<0 || x>=n || y>=n){
        return;
    }
    if(vis[x][y] || str[x][y]=='0') return;

    vis[x][y]=1;
    for(int i=0;i<8;i++){
        flood_fill(x+dx[i],y+dy[i],n);
    }


}

int main()
{
    int n,cnt=1;
    while(cin>>n){
        memset(vis,false,sizeof vis);
        for(int i=0;i<n;i++){
            cin>>str[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(str[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    flood_fill(i,j,n);
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n",cnt++,ans);
    }
}
