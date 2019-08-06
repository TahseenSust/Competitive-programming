#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

ll n,m[105];



int main()
{
    //freopen("uva.txt","w",stdout);

    int t;

    cin>>t;

    for(int tc=1;tc<=t;tc++){
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>m[i];
        }
        sort(m,m+n);

        ll ans=1;

        for(int i=0;i<n;i++){
            ans=(ans*(max(m[i]-i*1ll,0ll)))%mod;
        }
        printf("Case %d: %lld\n",tc,ans);
    }

}

