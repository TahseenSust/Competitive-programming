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


bool nisi[25005];

void mst()
{
    sort(G.begin(),G.end(),cmp);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int cnt=0;

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
            if(cnt==n-1){
                return;
            }
        }
    }
}



int main()
{
    int u,v,w;

    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0){
            return 0;
        }
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
        mst();
        vector<int>ans;
        for(int i=0;i<m;i++){
            if(nisi[i]==0){
                ans.push_back(G[i].w);
            }
        }
        if(ans.size()==0){
            cout<<"forest\n";
        }else{
            cout<<ans[0];
            for(int i=1;i<ans.size();i++){
                cout<<' '<<ans[i];
            }
            cout<<endl;
        }
    }



}
