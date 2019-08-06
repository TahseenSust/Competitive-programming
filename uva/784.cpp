#include <bits/stdc++.h>
using namespace std;
string str[50];
bool vis[500][500];


int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};


void flood_fill(int x,int y,int n)
{
    if(x<0 || y<0 || x>=n || y>=str[x].size()){
        return;
    }
    if(vis[x][y] || str[x][y]!=' ') return;

    vis[x][y]=1;
    str[x][y]='#';
    for(int i=0;i<4;i++){
        flood_fill(x+dx[i],y+dy[i],n);
    }


}

int main()
{
    //freopen("uva469.txt","w",stdout);
    int t;
    cin>>t;
    string ss;
    getline(cin,ss);
    while(t--){
        int n=0;
        while(getline(cin,ss)){
            if(ss[0]=='_'){
                break;
            }
            str[n++]=ss;
        }
        memset(vis,false,sizeof vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<str[i].size();j++){
                if(str[i][j]=='*'){
                    str[i][j]=' ';
                    flood_fill(i,j,n);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<str[i]<<endl;
        }
        cout<<ss<<endl;
    }
}
