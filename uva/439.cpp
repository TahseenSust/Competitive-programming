#include<bits/stdc++.h>
using namespace std;
bool vis[10][10];
int mv[10][10];
int fx[]={2,2,1,-1,-2,-2,1,-1};
int fy[]={1,-1,2,2,1,-1,-2,-2};

int bfs(int s1,int s2,int d1,int d2)
{
    memset(vis,0,sizeof(vis));
    memset(mv,0,sizeof(mv));
    queue<pair<int,int> >Q;
    Q.push({s1,s2});
    vis[s1][s2]=1;
    while(!Q.empty()){
        pair<int,int>top=Q.front();
        Q.pop();
        for(int k=0;k<8;k++){
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
            if(tx>=1 && ty>=1 && tx<=8 && ty<=8 && vis[tx][ty]==0){
                vis[tx][ty]=1;
                mv[tx][ty]=1+mv[top.first][top.second];
                Q.push({tx,ty});
            }
        }
    }
    return mv[d1][d2];
}
int main()
{
    string str1,str2;
    while(cin>>str1>>str2){
        int s1,s2,d1,d2;
        s1=str1[0]-'a'+1;
        s2=str1[1]-'0';
        d1=str2[0]-'a'+1;
        d2=str2[1]-'0';
        //cout<<s1<<' '<<s2<<' '<<d1<<' '<<d2<<endl;
        cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<bfs(s1,s2,d1,d2)<<" knight moves."<<endl;
    }
}
