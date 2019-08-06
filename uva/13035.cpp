#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007



ll power(ll n,ll p)
{
    if(p==0) return 1ll%MOD;
    if(p==1) return n%MOD;

    ll re=power(n,p/2)%MOD;
    re=((re%MOD)*(re%MOD))%MOD;

    if(p&1){
        re=((re%MOD)*(n%MOD))%MOD;
    }
    return re;
}

int main()
{
    int tc=1,t;
    ll ans,n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        ans=power(n,3)%MOD;
        ans=(ans+3*power(n,2)%MOD)%MOD;
        ans=(ans+2*power(n,1)%MOD)%MOD;
        ans=(ans*power(3,MOD-2)%MOD)%MOD;
        printf("Case %d: %lld\n",tc++,ans);
    }


}
