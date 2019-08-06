#include<bits/stdc++.h>
using namespace std;
#define DBG printf("ok\n");
const int N=10000000;
bitset<N> ck;
vector<int> primes;
void seive()
{
    ck.set();
    ck[0]=ck[1]=0;
    int limit=sqrt(N);
    for(long long i=2;i<=N;i++) if(ck[i])
    {
        primes.push_back(i);
        for(long long j=i*i;j<=N;j=j+2*i){
            ck[j]=0;
        }
    }
}
int List[N];
int listsz;
void prime_fact(int n)
{
    listsz=0;
    int sqrtN=(int)(sqrt(n));
    for(int i=0;primes[i]<=sqrtN;i++){
        while(n%primes[i]==0){
            n/=primes[i];
            List[listsz++]=primes[i];
        }
    }
    if(n>1){
        List[listsz++]=n;
    }
}

int lcm(int a,int b)
{
    return (a/__gcd(a,b))*b;
}
int ans;
int recur(int i,int j,int num,int numofele,int n)
{
    if(i==numofele) return 0;
    int x,y;
    for(x=i;x<numofele;x++){
        y=lcm(List[x],j);
        if(num&1) ans+=(n/y);
        else ans-=(n/y);
        recur(x+1,y,num+1,numofele,n);
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    seive();
    int n;
    while(cin>>n && n){
        ans=0;
        prime_fact(n);
        recur(0,1,1,listsz,n);
        cout<<n-ans<<endl;
    }
}

