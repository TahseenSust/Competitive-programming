#include<bits/stdc++.h>
using namespace std;
const int N=100000;
bitset<N> ck;
void seive()
{
    ck.set();
    ck[0]=ck[1]=0;
    for(long long i=2;i<=N;i++) if(ck[i])
    {
        for(long long j=i*i;j<=N;j=j+i){
            ck[j]=0;
        }
    }
}
int main()
{
    seive();
    int n,ans=0;
    while(cin>>n and n){
            ans=0;
        for(int i=2,j=n-2;i<=j;i++,j--){
            if(ck[i]==1&&ck[j]==1){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

