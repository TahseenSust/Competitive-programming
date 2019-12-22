#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz=100002;

bitset<sz>check;

vector<int>prime;


void sieve()
{
    prime.push_back(2);

    for(ll i=3;i<sqrt(sz);i++) if(!check[i])
    {
        for(ll j=i*i;j<sz;j+=i*2){
            check[j]=1;
        }
    }

    for(ll i=3;i<sz;i+=2) if(!check[i])
    {
        prime.push_back(i);
    }
}


bool isprime(int x)
{
    if(x==2) return 1;
    if(x%2==0 || x<=1) return 0;
    if(x<sz) return !check[x];
    for(int i=0;i<prime.size() && prime[i]<=sqrt(x);i++){
        if(x%prime[i]==0) return false;
    }
    return true;
}

int main()
{
    sieve();
    int n;

    while(scanf("%d",&n)!=EOF){
        bool flag=0;
        int a=n/2-1,b=n-a;
        if(n&1){
            if(isprime(n-2)){
                flag=1;
                a=2,b=n-2;
            }
        }else{
            for(int i=a;i>=0;i--){
                if(isprime(a) && isprime(b)){
                    flag=1;
                    break;
                }
                a--,b++;
            }
        }

        if(flag==0){
            printf("%d is not the sum of two primes!\n",n);
        }else{
            printf("%d is the sum of %d and %d.\n",n,a,b);
        }
    }
}
