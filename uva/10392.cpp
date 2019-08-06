#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=10000005;
bool chk[MX];
bool squre[MX];
vector<ll>prime;

void sieve()
{
    chk[0]=chk[1]=1;
    for(int i=4;i<=MX;i+=2){
        chk[i]=1;
    }
    prime.push_back(2);

    for(ll i=3;i<MX;i+=2){
        if(!chk[i]){
            prime.push_back(i);
            for(ll j=i*i;j<MX;j+=i){
                chk[j]=1;
            }
        }
    }
    for(int i=0;i<prime.size() && prime[i]*prime[i]<MX;i++){
        squre[prime[i]*prime[i]]=1;
    }
}

bool isprime(ll n)
{
    if(n<MX){
        return !chk[n];
    }
    for(int i=0;i<prime.size();i++){
        if(n%prime[i]==0){
            return 0;
        }
    }
    return 1;
}

bool issqure(ll n)
{
    if(n<MX){
        return squre[n];
    }
    for(int i=0;i<prime.size();i++){
        if(prime[i]*prime[i]==n){
            return 1;
        }
    }
    return 0;
}
vector<ll>factor(ll n)
{
    vector<ll>ans;
    if(n==1){
        ans.push_back(1);
        return ans;
    }


    for(int i=0;i<prime.size();i++){
        if(prime[i]*prime[i]*prime[i]>n){
            break;
        }
        ll cnt=1;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                ans.push_back(prime[i]);
                n/=prime[i];
                cnt++;
            }

        }
    }
    if(isprime(n)){
        ans.push_back(n);
    }else if(issqure(n)){
        ans.push_back(sqrt(n));
        ans.push_back(sqrt(n));
    }else if(n!=1){
        for(int i=0;i<prime.size();i++){
            if(n%prime[i]==0){
                while(n%prime[i]==0){
                    ans.push_back(prime[i]);
                    n/=prime[i];
                }
            }
        }
        if(n!=1){
            ans.push_back(n);
        }
    }
    return ans;
}

int main()
{
    sieve();
    ll n;
    while(scanf("%lld",&n) && n>=0){
        vector<ll>ans=factor(n);
        for(int i=0;i<ans.size();i++){
            printf("    %lld\n",ans[i]);
        }
        printf("\n");
    }
}
