#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mulmod(ll a, ll b, ll m)
{
    if(b==0) return 0;
    if(b&1) return (2ll * mulmod(a, b/2, m) % m + a) % m;
    return 2ll * mulmod(a, b/2, m) % m;
}
ll bigmod(ll a, ll p, ll m)
{
    ll ret = 1;
    while(p)
    {
        if(p&1) ret = mulmod(ret, a, m);
        a = mulmod(a, a, m);
        p/=2;
    }
    return ret;
}
bool millerRobin(ll p, int iter = 20)
{
    if(p==3 || p==2 || p==5) return true;
    if(p%2==0) return 0;
    if(p<3) return 0;

    for(int i = 0; i<iter; i++)
    {
        ll a = rand() % (p-4) + 2;
        ll s = p - 1;
        while(s%2==0) s/=2;
        ll mod = bigmod(a, s, p);
        if(mod==1 || mod==p-1) continue;
        bool flag = 0;
        s *= 2;
        while(s != p-1)
        {
            mod = mulmod(mod, mod, p);
            if(mod==p-1){
                flag = 1;
                break;
            }
            s*=2;
        }
        if(flag==0) return 0;
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    ll n;
    while( t-- ){
        scanf("%lld", &n);
        if(millerRobin(n)) printf("YES\n");
        else printf("NO\n");
    }
}
