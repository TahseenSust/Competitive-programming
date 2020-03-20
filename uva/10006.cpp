#include<bits/stdc++.h>
using namespace std;

bitset<65005>check;

void sieve()
{
    for(int i=4;i<65000;i+=2) check[i]=1;
    for(int i=3;i<65000;i+=2){
        if(check[i]==0){
            for(int j=2;i*j<65000;j++){
                check[i*j]=1;
            }
        }
    }
}

long long power(int n,int p,int m)
{
    if(p==0) return 1%m;
    if(p==1) return n%m;
    long long re=power(n,p/2,m)%m;
    re=(re*re)%m;
    if(p&1) re=(re*n)%m;
    return re%m;
//    int re=1;
//    for(int i=1;i<=p;i++){
//        re=(re*n)%m;
//    }
//    return re;
}

int main()
{
    sieve();
    int n;
    while(scanf("%d",&n) && n){
        bool flag=1;
        for(int i=2;i*i<=n;i++)
        if(power(i,n,n)!=i){
            //cout<<n<<' '<<i<<' '<<power(i,n,n)<<endl;
            flag=0;
            break;
        }
        if(flag && check[n]) printf("The number %d is a Carmichael number.\n",n);
        else printf("%d is normal.\n",n);
    }
}
