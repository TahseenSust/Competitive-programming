#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1000000000;
int n,mat[55][55],total;
 
 
int mst(int s=0)
{
    bool mark[55]={0};
    int cost=0,room=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pQ;
    pQ.push(make_pair(0,s));
 
    while(!pQ.empty()){
        int u=pQ.top().second;
        if(mark[u]){
            pQ.pop();
            continue;
        }
        mark[u]=1;
 
        room++;
        cost+=pQ.top().first;
        pQ.pop();
        for(int i=0;i<n;i++){
            if(i!=u && (mat[u][i]>0 || mat[i][u]>0) && !mark[i]){
                int w;
                if(mat[u][i]>0){
                    w=mat[u][i];
                    if(mat[i][u]>0){
                        w=min(w,mat[i][u]);
                    }
                }else{
                    w=mat[i][u];
                }
 
                pQ.push(make_pair(w,i));
            }
        }
    }
    if(room!=n){
        return -1;
    }
    return total-cost;
}
 
 
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
 
        scanf("%d",&n);
 
        total=0;
 
        int w;
 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&w);
                total+=w;
                mat[i][j]=w;
            }
        }
        int ans=mst();
        printf("Case %d: %d\n",tc,ans);
    }
}
