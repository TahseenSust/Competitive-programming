#include<bits/stdc++.h>
using namespace std;
bool visit[110];

void dfs(int s,vector<int>G[])
{
    for(int i=0;i<G[s].size();i++){
        if(visit[G[s][i]]==0){
            visit[G[s][i]]=1;
            dfs(G[s][i],G);
        }
    }
}
int main()
{
    int n,u,v,q,x;
    while(scanf("%d",&n) && n){

        vector<int>G[110];
        while(scanf("%d",&u) && u){
            while(scanf("%d",&v) && v){
                G[u].push_back(v);
            }
        }
        scanf("%d",&q);
        vector<vector<int> >ans;
        while(q--){
            scanf("%d",&x);
            memset(visit,0,sizeof visit);
            dfs(x,G);
            vector<int>tmep;
            for(int i=1;i<=n;i++){
                if(!visit[i]){
                    tmep.push_back(i);
                }
            }
            ans.push_back(tmep);
        }
        for(int i=0;i<ans.size();i++){
            printf("%d",ans[i].size());
            for(int j=0;j<ans[i].size();j++){
                printf(" %d",ans[i][j]);
            }
            printf("\n");
        }
    }
}
