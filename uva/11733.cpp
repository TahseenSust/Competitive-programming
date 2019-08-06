#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1000000000;
ll n,m,tk;

vector<pair<ll,ll>>G[10005];
vector<ll>mst_edge;
bool mark[10005]={0};
int parent[10005];
ll mst(ll s)
{

    ll cost=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >pQ;
    pQ.push(make_pair(0,s));

    while(!pQ.empty()){
        ll u=pQ.top().second;
        if(mark[u]){
            pQ.pop();
            continue;
        }
        mark[u]=1;
        mst_edge.push_back(pQ.top().first);
        cost+=pQ.top().first;
        pQ.pop();
        for(int i=0;i<G[u].size();i++){
            ll v=G[u][i].first;
            if(!mark[v]){
                parent[v]=u;
                pQ.push(make_pair(G[u][i].second,v));
            }
        }
    }

    return cost;
}




int main()
{
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%lld%lld%lld",&n,&m,&tk);
        ll u,v,w;
        for(int i=0;i<10005;i++){
            G[i].clear();
        }
        for(int i=0;i<m;i++){
            scanf("%lld%lld%lld",&u,&v,&w);
            G[u].push_back(make_pair(v,w));
            G[v].push_back(make_pair(u,w));
        }
        memset(mark,false,sizeof mark);
        ll ans=0,airport=0;
        mst_edge.clear();
        for(int i=1;i<=n;i++){
            if(!mark[i]){
                ans+=mst(i);
                airport++;
            }
        }
        ans=ans+tk*airport;
        for(int i=0;i<mst_edge.size();i++){
            if(ans>=ans-mst_edge[i]+tk){
                ans=ans-mst_edge[i]+tk;
                airport++;
            }
        }
        printf("Case #%d: %lld %lld\n",tc,ans,airport);
    }
}
