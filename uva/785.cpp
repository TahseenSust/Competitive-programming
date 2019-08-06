#include <bits/stdc++.h>
using namespace std;
string str[500];
bool vis[500][500];


int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};


void flood_fill(int x,int y,int n,char ck)
{
    if(x<0 || y<0 || x>=n || y>=str[x].size()){
        return;
    }
    if(vis[x][y] || (str[x][y]!=' ' && str[x][y]!=ck)) return;

    vis[x][y]=1;
    str[x][y]=ck;
    for(int i=0;i<4;i++){
        flood_fill(x+dx[i],y+dy[i],n,ck);
    }


}


int main()
{
    //freopen("uva469.txt","w",stdout);
    string ss;
    while(getline(cin,ss)){
        int n=0;
        str[n++]=ss;
        if(ss[0]!='_'){
            while(getline(cin,ss)){
                if(ss[0]=='_'){
                    break;
                }
                str[n++]=ss;
            }
        }
        char border=' ';
        for(int i=0;i<n && border==' ';i++){
            for(int j=0;j<str[i].size();j++){
                if(str[i][j]!=' '){
                    border=str[i][j];
                    break;
                }
            }
        }
        memset(vis,false,sizeof vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<str[i].size();j++){
                if(vis[i][j]==0 && str[i][j]!=border && str[i][j]!=' '){

                    flood_fill(i,j,n,str[i][j]);

                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<str[i]<<endl;
        }
        cout<<ss<<endl;
    }
}
