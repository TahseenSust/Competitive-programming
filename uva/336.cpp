#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
vector<int> edge[100],cost[100];
int d[100];
void set_inf()
{
    for(int i=0;i<100;i++) d[i]=inf;
}
int ans[100],o;
void bfs(int s,int ttl,int k)
{
    set_inf();
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        int ucost=d[u];
        for(int i=0;i<edge[u].size();i++){
            int v=edge[u][i],vcost=cost[u][i]+ucost;
            if(d[v]>vcost){
                d[v]=vcost;
                q.push(v);
            }
        }
    }
    o=0;
    for(int i=1;i<k;i++){
        if(d[i]==inf||d[i]>ttl)
            ans[o++]=i;
    }
}
int main()
{
    int n,cn=0;
    while(cin>>n&&n){
        int x,y,k=1;
        bool name[100]={0};
        map<int,int> mp;
        mp.clear();
        for(int i=0;i<n;i++){
            cin>>x>>y;
            if(mp[x]==0){
                mp[x]=k++;
            }
            if(mp[y]==0){
                mp[y]=k++;
            }
            //cout<<mp[x]<<' '<<mp[y]<<endl;
            edge[mp[x]].push_back(mp[y]);
            edge[mp[y]].push_back(mp[x]);
            cost[mp[x]].push_back(1);
            cost[mp[y]].push_back(1);
        }
        while(cin>>x>>y){
            if(x==0&&y==0)
                break;
            bfs(mp[x],y,k);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cn,o,x,y);
        }
        for(int i=0;i<k;i++){
            edge[i].clear();
            cost[i].clear();
        }
    }
}
