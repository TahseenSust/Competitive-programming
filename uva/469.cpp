#include <bits/stdc++.h>
using namespace std;
string str[500];
bool vis[500][500];


int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

pair<int,int>to_num(string s)
{
    pair<int,int>n;
    n.first=0;
    n.second=0;
    int f=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            f=1;
            continue;
        }
        if(f==0){
            n.first=n.first*10+(s[i]-'0');
        }else{
            n.second=n.second*10+(s[i]-'0');
        }
    }
    return n;
}

int flood_fill(int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>=n || y>=m){
        return 0;
    }
    if(vis[x][y] || str[x][y]=='L') return 0;

    vis[x][y]=1;
    int re=1;
    for(int i=0;i<8;i++){
        re+=flood_fill(x+dx[i],y+dy[i],n,m);
    }
    return re;


}

int main()
{
    //freopen("uva469.txt","w",stdout);
    int t;
    cin>>t;
    string ss;


    getline(cin,ss);
    getline(cin,ss);
    while(t--){


        int n=0,m=0;
        for(int i=0;i<100;i++){
            str[i].clear();
        }
        while(getline(cin,ss)){
            if(ss[0]!='L' && ss[0]!='W'){
                break;
            }
            m=ss.size();
            str[n]=ss;
            n++;
        }
        memset(vis,false,sizeof vis);
        pair<int,int>num=to_num(ss);
        cout<<flood_fill(num.first-1,num.second-1,n,m)<<endl;
        while(getline(cin,ss)){
            if(ss.size()==0){
                break;
            }
            num=to_num(ss);
            memset(vis,false,sizeof vis);
            cout<<flood_fill(num.first-1,num.second-1,n,m)<<endl;
        }
        if(t)
            cout<<endl;
    }
}
