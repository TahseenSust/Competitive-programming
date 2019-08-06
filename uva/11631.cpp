#include<bits/stdc++.h>
using namespace std;

int parent[200005],n,m,sum;

struct edge{
    int u,v,w;
    bool operator<(const edge& p){
        return w<p.w;
    }
};

int root(int r)
{
    if(parent[r]==r){
        return r;
    }
    return parent[r]=root(parent[r]);
}
vector<edge>e;
void mst()
{
    sort(e.begin(),e.end());
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int cnt=0,s=0;
    for(int i=0;i<m;i++){
        int u=root(e[i].u);
        int v=root(e[i].v);
        if(u!=v){
            parent[u]=v;
            s+=e[i].w;
            cnt++;
        }
        if(cnt==n-1){
            break;
        }
    }
    sum=s;
}
int main()
{
    int u,v,w;
    while(cin>>n>>m && n && m){
        int mut=0;
        e.clear();
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            mut+=w;
            edge tmp;
            tmp.u=u;
            tmp.v=v;
            tmp.w=w;
            e.push_back(tmp);
        }
        mst();
        cout<<mut-sum<<endl;
    }
}
