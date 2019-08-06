/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=484

#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
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
    int n;
    while(cin>>n and n){
        for(int i=3,j=n-3;i<=j;i++,j--){
            if(ck[i]==1&&ck[j]==1){
                printf("%d = %d + %d\n",n,i,j);
                break;
            }
        }
    }
}

