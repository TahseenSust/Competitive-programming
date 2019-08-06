#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
bitset<N>ck;
void sieve()
{
    ck.set();
    ck[0]=ck[1]=0;
    int s=sqrt(N);
    for(int i=4;i<N;i+=2){
        ck[i]=0;
    }
    for(int i=3;i<s;i+=2) if(ck[i])
    {
        for(int j=2*i;j<N;j+=i){
            ck[j]=0;
        }
    }
}

bool isprime(int n)
{
    return ck[n];
}

int rev(int n)
{
    int re=0;
    for(int i=1;i<=n;i*=10){
        re=re*10+(n/i)%10;
    }
    return re;
}

int main()
{
    sieve();
    //freopen("input.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        if(ck[n]){
            int r=rev(n);
            if(ck[r] && r!=n){
                printf("%d is emirp.\n",n);
            }else{
                printf("%d is prime.\n",n);
            }
        }else{
            printf("%d is not prime.\n",n);
        }
    }
}
