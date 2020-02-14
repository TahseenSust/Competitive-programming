#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000007;
///transition-> for(i=0;i<x;i++) f[n]=a0*f[n-1]+a1*f[n-2]+.... here tr[]={a0,a1,a2,...}
///S=first initial value F0,F1,F2,...
///k is 0 indexed
long long linearRec(vector<long long> S, vector<long long> tr, long long k) {
	long long n = S.size();
	if(n==0) return 0;
	auto combine = [&](vector<long long> a, vector<long long> b) {
		vector<long long> res(n * 2 + 1);
		for (long long i=0; i<n+1; i++) for (long long j=0; j<n+1; j++)
			res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
		for (long long i = 2 * n; i > n; --i) for (long long j=0; j<n; j++)
			res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % mod;
		res.resize(n + 1);
		return res;
	};
 
	vector<long long> pol(n + 1), e(pol);
	pol[0] = e[1] = 1;
 
	for (++k; k; k /= 2) {
		if (k % 2) pol = combine(pol, e);
		e = combine(e, e);
	}
 
	long long res = 0;
	for (long long i=0; i<n; i++) res = (res + pol[i + 1] * S[i]) % mod;
	return res;
}

int main(int argc, char const *argv[])
{
	long long a, b, n;
	scanf("%lld %lld", &a, &b);
	vector<ll> tt(b,0);
	tt[0] = 1;
	tt[b - 1] = 1;
	printf("%lld\n",linearRec(vector<ll>(b,1),tt,a));
	return 0;
}
