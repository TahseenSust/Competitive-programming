#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct edge{
    int u,v,w;
    bool operator <(const edge& p) const
    {
        return w<p.w;
    }
};
 
vector<edge>graph;
int par[110];
bool vis[110];
 
int find_root(int u)
{
    return (par[u]==u)?u:(par[u]=find_root(par[u]));
}
 
void dfs(int s,vector<int>G[])
{
    if(vis[s]==1){
        return;
    }
    vis[s]=1;
    for(int i=0;i<G[s].size();i++){
        dfs(G[s][i],G);
    }
}
 
int mst(int n)
{
    sort(graph.begin(),graph.end());
    for(int i=0;i<=n;i++){
        par[i]=i;
    }
    int cnt=0,s=0;
    vector<int>G[110];
    for(int i=0;i<(int)graph.size();i++){
        int u=graph[i].u;
        int v=graph[i].v;
        int w=graph[i].w;
        int root_u=find_root(u);
        int root_v=find_root(v);
        if(root_u!=root_v)
        {
            G[u].push_back(v);
            G[v].push_back(u);
 
            par[root_u]=root_v;
            cnt++;
            s+=w;
            if(cnt==n-1){
                break;
            }
        }
    }
    memset(vis,false,sizeof vis);
    dfs(0,G);
    int connct=0;
    for(int i=0;i<n;i++){
        connct+=vis[i];
    }
    if(connct!=n){
        return -1;
    }
    return s;
}
 
int main()
{
    int n,u,v,w;
    int t;
    cin>>t;
 
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        string s1,s2;
        int w,k=0;
        map<string,int>mp;
        graph.clear();
        for(int i=0;i<n;i++){
            cin>>s1>>s2>>w;
            if(mp.find(s1)==mp.end()){
                mp[s1]=k++;
            }
            if(mp.find(s2)==mp.end()){
                mp[s2]=k++;
            }
            edge get;
            get.u=mp[s1];
            get.v=mp[s2];
            get.w=w;
            graph.push_back(get);
        }
        int mn=mst(k);
        printf("Case %d: ",tc);
        if(mn!=-1){
            printf("%d\n",mn);
        }else{
            printf("Impossible\n");
        }
 
    }
}
