#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 300000
#define F 250000
#define P 22001
const int N=MAX;
bitset<N> ck;
int primes[P];
void seive()
{
    ck.set();
    ck[0]=ck[1]=0;
    int limit=sqrt(N),cnt=1;
    for(int i=4;i<N;i=i+2) ck[i]=0;
    for(int i=3;i<limit;i=i+2) if(ck[i])
    {
        for(int j=2*i;j<N;j=j+i){
            ck[j]=0;
        }
    }
    for(int i=2;i<N;i++) if(ck[i])
    {
        primes[cnt++]=i;
    }
}

double fib[F]={0,1};
void fibprime()
{
    bool div=false;
    for(int i=2;i<F;i++){
        if(div)
        {
            fib[i]=fib[i-1]+fib[i-2]/10;
            div=false;
        }
        else
            fib[i]=fib[i-1]+fib[i-2];

        if(fib[i]>=1e9)
        {
            fib[i]/=10;
            div=true;
        }
    }
}


int main()
{
    //freopen("input.txt","r",stdin);
    seive();
    fibprime();
    int n;
    fib[2]=2;
    fib[3]=3;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",(int)fib[primes[n]]);
    }
    return 0;
}
