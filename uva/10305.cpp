#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD=1000000000+7;
int n,m;

int main()
{
    //freopen("out.txt","w",stdout);
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        int u,v;
        vector<int>G[105];
        bool vis[105]={0};
        int degree[105]={0};

        for(int i=0;i<m;i++){
            cin>>u>>v;
            G[u].push_back(v);
            degree[v]++;
        }
        vector<int>ans;
        for(int i=1;i<=n;i++){
            vector<int>tmp;
            for(int j=1;j<=n;j++){
                if(degree[j]==0 && vis[j]==0){
                    ans.push_back(j);
                    tmp.push_back(j);
                }
            }
            for(int j=0;j<tmp.size();j++){
                int d=tmp[j];
                vis[d]=1;
                for(int k=0;k<G[d].size();k++){
                    degree[G[d][k]]--;
                }
            }
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<' '<<ans[i];
        }
        cout<<endl;
    }
}
