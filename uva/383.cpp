#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
vector<int>G[50];

int bfs(int s,int d)
{
    bool vis[35]={0};
    int dis[35];
    memset(dis,-1,sizeof dis);
    queue<int>Q;
    dis[s]=0;
    vis[s]=1;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(vis[v]==0){
                vis[v]=1;
                dis[v]=1+dis[u];
                Q.push(v);
            }
        }
    }
    return dis[d];
}
int main()
{
    //freopen("shipment.txt","w",stdout);
    int t;
    scanf("%d",&t);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(int tc=1;tc<=t;tc++){
        mp.clear();
        for(int i=0;i<40;i++){
            G[i].clear();
        }

        int m,n,p,x,k=0;
        cin>>m>>n>>p;
        string s1,s2;
        for(int i=0;i<m;i++){
            cin>>s1;
            if(mp[s1]==0){
                mp[s1]=k++;
            }
        }

        for(int i=0;i<n;i++){
            cin>>s1>>s2;
            G[mp[s1]].push_back(mp[s2]);
            G[mp[s2]].push_back(mp[s1]);
        }
        printf("DATA SET  %d\n\n",tc);
        for(int i=0;i<p;i++){
            cin>>x>>s1>>s2;
            int leg=bfs(mp[s1],mp[s2]);
            if(leg>=0){
                printf("$%d\n",x*leg*100);
            }else{
                printf("NO SHIPMENT POSSIBLE\n");
            }
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
}

