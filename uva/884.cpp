#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll>prime;
ll precal[1000005];

void sieve()
{
    bitset<1000005>chk;

    for(ll i=2;i<=1000000;i++){
        if(chk[i]==0){
            prime.push_back(i);
            for(ll j=2;i*j<=1000000;j++){
                chk[j*i]=1;
            }
        }
    }
    for(int i=0;i<prime.size();i++){
        ll x=prime[i];
        ll cnt=1;
        while(x<=1000000){
            for(int j=x;j<=1000000;j+=x){
                precal[j]++;
            }
            x*=prime[i];
        }
    }
    for(int i=1;i<=1000000;i++){
        precal[i]+=precal[i-1];
    }
}

int main()
{
    //freopen("uva.txt","r",stdin);
    sieve();
    ll n;
    while(scanf("%lld",&n)!=EOF){
        printf("%lld\n",precal[n]);
    }
}
