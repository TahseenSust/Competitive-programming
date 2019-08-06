#include<bits/stdc++.h>
using namespace std;
const int INF=100000000;
int n;
int capacity[109][109];
vector<int>G[109];
int bfs(int s,int t,vector<int>&parent)
{
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,int> >Q;
    Q.push({s,INF});
    while(!Q.empty()){
        int cur=Q.front().first;
        int flow=Q.front().second;
        Q.pop();

        for(int i=0;i<G[cur].size();i++){
            int next=G[cur][i];
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next]=cur;
                int new_flow=min(flow,capacity[cur][next]);
                if(next==t){
                    return new_flow;
                }
                Q.push({next,new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s,int t)
{
    int flow=0;
    vector<int>parent(n+5);
    int new_flow;
    while(new_flow=bfs(s,t,parent)){
        flow+=new_flow;
        int cur=t;
        while(cur!=s){
            int prev=parent[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int s,t,c,u,v,cost,tc=1;
    while(cin>>n && n){
        cin>>s>>t>>c;
        for(int i=0;i<c;i++){
            cin>>u>>v>>cost;
            G[u].push_back(v);
            G[v].push_back(u);
            capacity[u][v]+=cost;
            capacity[v][u]+=cost;
        }
        printf("Network %d\n",tc++);
        printf("The bandwidth is %d.\n\n",maxflow(s,t));
        memset(capacity,0,sizeof capacity);
        for(int i=0;i<=105;i++){
            G[i].clear();
        }
    }
}
