#include<bits/stdc++.h>
using namespace std;

int parent[1000],n,m;
double sum;

struct edge{
    double u,v,w;
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
vector<pair<double,double>>ans;
void mst()
{
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    int cnt=0;
    double s=0;
    for(int i=0;i<e.size();i++){
        int u=root(e[i].u);
        int v=root(e[i].v);
        if(u!=v){
            parent[u]=v;
            ans.push_back({e[i].u,e[i].v});
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
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    bool f=0;
    while(t--){
        if(f){
            cout<<endl;
        }
        f=1;
        cin>>n;
        sum=0;
        e.clear();
        pair<double,double>cor[110];
        for(int i=0;i<n;i++){
            cin>>cor[i].first>>cor[i].second;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double dis;
                dis=(cor[i].first-cor[j].first)*(cor[i].first-cor[j].first)+(cor[i].second-cor[j].second)*(cor[i].second-cor[j].second);
                dis=sqrt(dis);
                edge tmp;
                tmp.u=i+1;
                tmp.v=j+1;
                tmp.w=dis;
                e.push_back(tmp);
            }
        }
        mst();
        cout<<setprecision(2)<<fixed<<sum<<endl;
    }
}
