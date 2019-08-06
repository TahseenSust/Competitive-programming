#include<bits/stdc++.h>
using namespace std;
vector<int>G[1000];
bool visit[1000];
int path[1000];
int level[1000];
bool bfs(int s,int d)
{
    memset(visit,0,sizeof visit);
    memset(path,-1,sizeof path);
    memset(level,-1,sizeof level);
    queue<int>Q;
    Q.push(s);
    visit[s]=1;
    level[s]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(visit[v]==0){
                path[v]=u;
                visit[v]=1;
                level[v]=1+level[u];
                Q.push(v);
            }
        }
    }
    if(level[d]==-1){
        return false;
    }
    return true;
}
void printpath(int a,int b,map<int,string>st)
{
    if(a==b){
        return;
    }
    printpath(a,path[b],st);
    cout<<st[path[b]]<<' '<<st[b]<<endl;
}
int main()
{
    //freopen("762.txt","w",stdout);
    int n,k=-1;
    while(cin>>n){
        for(int i=0;i<1000;i++) G[i].clear();
        if(k!=-1){
            cout<<endl;
        }
        k=0;
        string u,v;
        map<string,int>mp;
        map<int,string>st;
        for(int i=0;i<n;i++){
            cin>>u>>v;
            if(mp.find(u)==mp.end()){
                mp[u]=k;
                st[k]=u;
                k++;
            }
            if(mp.find(v)==mp.end()){
                mp[v]=k;
                st[k]=v;
                k++;
            }
            G[mp[u]].push_back(mp[v]);
            G[mp[v]].push_back(mp[u]);
        }
        cin>>u>>v;
        if(mp.find(u)==mp.end()){
            mp[u]=k;
            st[k]=u;
            k++;
        }
        if(mp.find(v)==mp.end()){
            mp[v]=k;
            st[k]=v;
            k++;
        }
        int ver=bfs(mp[u],mp[v]);
        int a=mp[u],b=mp[v];
        if(ver==0){
            cout<<"No route\n";
            continue;
        }
        vector<pair<string,string>>route;
        printpath(a,b,st);
    }
}
