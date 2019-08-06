#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1000000000;
int n;
double x[1005],y[1005],r;

vector<pair<int,double>>G[1005];
bool mark[1005]={0};

vector<int>state[1005];


double mst(int s,int city)
{
    double cost=0;
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>> >pQ;
    pQ.push(make_pair(0.0,s));

    while(!pQ.empty()){
        int u=pQ.top().second;
        if(mark[u]){
            pQ.pop();
            continue;
        }
        mark[u]=1;
        state[city].push_back(u);

        cost+=pQ.top().first;
        pQ.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].first;
            if(!mark[v]){
                pQ.push({G[u][i].second,v});
            }
        }
    }

    return cost;
}


double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n>>r;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        for(int i=0;i<1005;i++){
            G[i].clear();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    double d=dis(x[i],y[i],x[j],y[j]);
                    if(d<=r){
                        G[i].push_back({j,d});
                    }
                }
            }
        }
        double ans=0;
        int city=0;
        for(int i=0;i<1005;i++){
            state[i].clear();
        }
        memset(mark,false,sizeof mark);
        for(int i=0;i<n;i++){
            if(!mark[i]){
                ans+=mst(i,city);
                city++;
            }
        }
        for(int i=0;i<1005;i++){
            G[i].clear();
        }

        for(int i=0;i<city;i++){
            for(int j=0;j<city;j++){
                if(j!=i){
                    double d=1e10;
                    for(int k=0;k<state[i].size();k++){
                        for(int l=0;l<state[j].size();l++){
                            int u=state[i][k],v=state[j][l];
                            d=min(d,dis(x[u],y[u],x[v],y[v]));
                        }
                    }
                    G[i].push_back({j,d});
                }
            }
        }
        memset(mark,false,sizeof mark);
        double ans2=mst(0,0);
        printf("Case #%d: %d %d %d\n",tc,city,(int)round(ans),(int)round(ans2));
    }
}
