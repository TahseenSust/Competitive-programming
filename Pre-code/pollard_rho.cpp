#include <bits/stdc++.h>
#define lll __int128
#define ull unsigned long long
#define ulll unsigned lll
#define mx 1000007
#define ll long long
using namespace std;

bool arr[mx];
int prime[mx];
int cnt= 0;
vector<ll> Q;
ll Mx;

ll sq( ll n )
{
    ll s= sqrt(n);

    if( (s-1)*(s-1)==n )
        return s-1;
    if( (s+1)*(s+1)==n )
        return s+1;
    return s;
}

void sieve()
{
    prime[cnt++]= 2;

    for( ll i=3; i<mx; i+=2 )
    {
        if(!arr[i])
        {
            prime[cnt++]= i;

            for( ll j=i*i; j<mx; j+=2*i )
                arr[j]= 1;
        }
    }
}

ull mulmod(ull a, ull t, ull mm) {
	ull r = 1;
	for (; t; t >>= 1, a = (ulll)(a) * a % mm)if (t & 1)r = (ulll)(r) * a % mm; return r;
}

ll mul(ll a,ll b,ll p)
{
    ll tmp=(a*b-(ll)((long double)a/p*b+1e-8)*p);
    return tmp<0?tmp+p:tmp;
}

ll bigmod( ll x, ll y, ll m )
{
    ll res= 1%m;

    while(y>0)
    {
        if( y&1 )
            res= mulmod( res,x,m );
        x= mulmod( x,x,m );
        y>>= 1;
    }

    return res%m;
}

bool isPrime(ull n) {
	static const int jp[] = {2, 3, 5, 7, 11, 13, 17, 19};
	if (n == 1)return 0;
	for (int p : jp)if (n % p == 0)return n == p;
	ull r = n - 1, x, y; int e = 0;
	while (~r & 1)r >>= 1, ++e;
	for (int p : jp) {
		x = mulmod(p, r, n);
		for (int t = 0; t < e && x > 1; ++t) {
			y = (lll)x * x % n;
			if (y == 1 && x ^ (n - 1))return 0; x = y;
		}
		if (x ^ 1)return 0;
	} return 1;
}

ll rho(ll n,ll c)
{
    ll k=2,x=rand()%n,y=x,p=1;
    for(ll i=1; p==1; i++)
    {
        x=(mul(x,x,n)+c)%n;
        p=y>x?y-x:x-y;
        p=__gcd((ull)n,(ull)p);
        if(i==k)
            y=x,k+=k;
    }
    return p;
}

unordered_map<ll,int>mp;

void solve(ll n)
{
    if(n==1)
        return;
    if(isPrime(n))
    {
        mp[n]++;
        return;
    }
    ll t=n;
    while(t==n)
        t=rho(n,rand()%(n-1)+1);
    solve(t);
    solve(n/t);
}

int main()
{
    sieve();

    ll x;
    scanf("%lld", &x);

    ll ans= 1;

    if(x!=1)
    {
        solve(x);
    }

    for( auto p: mp ){
    	cout<<p.first<<' '<<p.second<<endl;
    	ans= ( ans*(p.second+1) );
    }

    printf("%lld\n", ans);
}
