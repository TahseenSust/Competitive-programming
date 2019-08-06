#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;

struct edge{
    int u,v,w;
};

vector<edge>G;



bool cmp(edge a,edge b)
{
    return a.w>b.w;
}

int parent[1005];


int findparent(int u)
{
    if(parent[u]!=u){
        return parent[u]=findparent(parent[u]);
    }
    return u;
}


int mst()
{
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int cnt=0,cost=INT_MAX;

    for(int i=0;i<m;i++)
    {
        int root_u=findparent(G[i].u);
        int root_v=findparent(G[i].v);
        //cout<<root_u<<' '<<root_v<<endl;
        if(root_u!=root_v)
        {
            parent[root_u]=root_v;
            cnt++;
            cost=min(cost,G[i].w);
            if(cnt==n-1){
                return cost;
            }
        }
    }

    return INT_MAX;
}




int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int u,v,w,t,tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        G.clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            edge tmp;
            tmp.u=u;
            tmp.v=v;
            tmp.w=w;
            G.push_back(tmp);
        }
        sort(G.begin(),G.end(),cmp);

        int ans1=mst();

        printf("Case #%d: %d\n",tc++,ans1);


    }



}
