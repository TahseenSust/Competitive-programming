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
    return a.w<b.w;
}

int parent[1005];


int findparent(int u)
{
    if(parent[u]!=u){
        return parent[u]=findparent(parent[u]);
    }
    return u;
}


bool nisi[100005];

int mst()
{
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int cnt=0,cost=0;

    for(int i=0;i<m;i++)
    {
        int root_u=findparent(G[i].u);
        int root_v=findparent(G[i].v);
        //cout<<root_u<<' '<<root_v<<endl;
        if(root_u!=root_v)
        {
            parent[root_u]=root_v;
            cnt++;
            nisi[i]=1;
            cost+=G[i].w;
            if(cnt==n-1){
                return cost;
            }
        }
    }
    return INT_MAX;
}

int mst2(int x)
{
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int cnt=0,cost=0;

    for(int i=0;i<m;i++)
    {
        if(i!=x){
            int root_u=findparent(G[i].u);
            int root_v=findparent(G[i].v);
            //cout<<root_u<<' '<<root_v<<endl;
            if(root_u!=root_v)
            {
                parent[root_u]=root_v;
                cnt++;
                cost+=G[i].w;
                if(cnt==n-1){
                    return cost;
                }
            }
        }
    }
    return INT_MAX;

}



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int u,v,w,t;
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
        memset(nisi,false,sizeof nisi);
        sort(G.begin(),G.end(),cmp);

        int ans1=mst(),ans2=INT_MAX;

        for(int i=0;i<m;i++){
            if(nisi[i]==1){
                ans2=min(ans2,mst2(i));
            }
        }

        cout<<ans1<<' '<<ans2<<endl;

    }



}
