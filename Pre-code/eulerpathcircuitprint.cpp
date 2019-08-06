#include<bits/stdc++.h>
using namespace std;
/// Assuming Graph is euler circuit/path
vector<int>G[550];
int node;

int dfs(int u,bool visited[])
{
    int cnt=1;
    visited[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=-1 && visited[v]==0){
            cnt+=dfs(v,visited);
        }
    }
    return cnt;
}


void remove_edge(int u,int v)
{
    int i=find(G[u].begin(),G[u].end(),v)-G[u].begin();
    G[u][i]=-1;
    i=find(G[v].begin(),G[v].end(),u)-G[v].begin();
    G[v][i]=-1;
}

void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

bool valid(int u,int v)
{
    int cnt=0;
    for(int i=0;i<G[u].size();i++){
        if(G[u][i]!=-1){
            cnt++;
        }
    }
    if(cnt==1) return 1;// v is only adjacent

    int count1=0,count2=0;

    bool visited[node+5]={0};
    // count reachable nodes
    count1=dfs(u,visited);
    remove_edge(u,v);
    memset(visited,false,sizeof visited);
    count2=dfs(v,visited);
    add_edge(u,v);
    return (count1>count2)?false:true;
}



void eulerpath(int u)
{
    cout<<u<<endl;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];

        if(v!=-1 && valid(u,v)){ // see if u-v if is bridge
            remove_edge(u,v);
            eulerpath(v);
        }

    }

}


void printpath()
{
    int u=1;
    for(int i=1;i<=node;i++){
        if(G[i].size()&1){
            u=i;
            break;
        }
    }
    eulerpath(u);

}


int main()
{
    int m,u,v;
    node=500;
    cin>>m;
    while(m--){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    printpath();
}
