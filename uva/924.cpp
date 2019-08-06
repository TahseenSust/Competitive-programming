#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define INF 1000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

vector<int>G[2504];
bool vis[2505];

pii bfs(int s)
{
    memset(vis,0,sizeof vis);
    queue<pii>Q;
    Q.push({s,1});
    vis[s]=1;
    int ans=0,cnt=0,d=1,day=-1;
    while(!Q.empty()){
        pii u=Q.front();
        Q.pop();
        if(u.second>d){
            if(cnt>ans){
                ans=cnt;
                day=d;
            }
            d++;
            cnt=0;
        }
        for(int i=0;i<G[u.first].size();i++){
            int v=G[u.first][i];
            if(vis[v]==0){
                cnt++;
                vis[v]=1;
                Q.push({v,u.second+1});
            }
        }


    }
    return {ans,day};
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int e,koyta,v;
    cin>>e;
    for(int i=0;i<e;i++){
        cin>>koyta;
        while(koyta--){
            cin>>v;
            G[i].push_back(v);
        }
    }
    int q,s;
    cin>>q;
    while(q--){
        cin>>s;
        pii ans=bfs(s);
        if(ans.second==-1){
            cout<<"0"<<endl;
        }else{
            cout<<ans.first<<' '<<ans.second<<endl;
        }
    }
}

