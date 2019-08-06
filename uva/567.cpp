#include<bits/stdc++.h>
using namespace std;
#define N 100
vector<int> G[N];
bool visit[N];
int dis[N];

int bfs(int src, int des)
{
    memset(visit,0,sizeof visit);
    memset(dis,0,sizeof dis);
    queue<int>Q;
    Q.push(src);
    dis[src]=0;
    while(!Q.empty()){
        int u=Q.front();Q.pop();

        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(!visit[v]){
                visit[v]=true;
                dis[v]=dis[u]+1;
                Q.push(v);
            }
        }
    }
    return dis[des];
}
int main()
{

    //freopen("input.txt","r",stdin);
    int n=1,e,u,v,ans,cn=1;

    while(cin>>e){
        n=1;
        for(int i=0;i<N;i++){
            G[i].clear();
        }
        while(e--){
            cin>>u;
            G[n].push_back(u);
            G[u].push_back(n);
        }
        n++;
        for(int i=2;i<20;i++){
            cin>>e;
            while(e--){
                cin>>u;
                G[n].push_back(u);
                G[u].push_back(n);
            }
            n++;
        }
        cin>>e;
        printf("Test Set #%d\n",cn++);
        while(e--){
            cin>>u>>v;
            ans=bfs(u,v);
            printf("%2d to %2d: %d\n",u,v,ans);
        }
        printf("\n");

    }
}
