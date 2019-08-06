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

int parent[100005];


int findparent(int u)
{
    if(parent[u]!=u){
        return parent[u]=findparent(parent[u]);
    }
    return u;
}



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int u,v,w,t,tc=1;
    for(int i=0;i<=100000;i++){
        parent[i]=i;
    }
    int cnt=0;
    while(cin>>u)
    {
        if(u!=-1){
            cin>>v;
            int root_u=findparent(u);
            int root_v=findparent(v);
            if(root_u==root_v){
                cnt++;
            }else{
                parent[root_u]=root_v;
            }
        }else{
            cout<<cnt<<endl;
            cnt=0;
            for(int i=0;i<=100000;i++){
                parent[i]=i;
            }
        }
    }



}
