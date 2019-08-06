#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long l,r;
    while(scanf("%lld%lld",&l,&r)){
        if(l==0 || r==0){
            return 0;
        }
        long long mx=0,chain,n;
        long long p=l,q=r;
        if(p>q){
            swap(p,q);
        }
        for(long long i=p;i<=q;i++){
            chain=1;
            long long x=i;
            if(x&1){
                x=3*x+1;
            }else{
                x/=2;
            }
            while(x!=1){
                if(x&1){
                    x=3*x+1;
                }else{
                    x/=2;
                }
                chain++;
            }
            if(chain>mx){
                mx=chain;
                n=i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",p,q,n,mx);
    }
}
