#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define INF (1<<18)

struct dt{
    ll x,y,z;
};

vector<dt>info;
ll dp[3000];
ll LIS(int u)
{
    if(dp[u]!=-1){
        return dp[u];
    }
    ll mx=0,ln=0;
    for(int v=0;v<info.size();v++){
        if(info[v].x<info[u].x && info[v].y<info[u].y){
            ln=info[v].z+LIS(v);
            mx=max(mx,ln);
        }
    }
    return dp[u]=mx;
}

int main()
{
    //freopen("uva.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ara[4];
    int tc=1;
    while(cin>>n && n){
        info.clear();
        for(int i=0;i<n;i++){
            cin>>ara[0]>>ara[1]>>ara[2];
            sort(ara,ara+3);
            do{
                dt tmp;
                tmp.x=ara[0];
                tmp.y=ara[1];
                tmp.z=ara[2];
                info.push_back(tmp);
            }while(next_permutation(ara,ara+3));
        }
        ll mx=0,ln;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<info.size();i++){
            ln=info[i].z+LIS(i);
            mx=max(mx,ln);
        }
        printf("Case %d: maximum height = %lld\n",tc++,mx);
    }
}
