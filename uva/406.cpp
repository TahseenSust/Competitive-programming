#include<bits/stdc++.h>
using namespace std;
#define MX 10000
bitset<MX>ch;
vector<int>prime;
void sieve()
{
    ch.set();
    ch[0]=ch[1]=0;
    prime.push_back(1);
    for(int i=2;i<=MX;i++){
        if(ch[i]==1){
            prime.push_back(i);
            for(int j=2;j*i<=MX;j++){
                ch[i*j]=0;
            }
        }
    }
}
int main()
{
    int n,c;
    sieve();
    while(scanf("%d%d",&n,&c)!=EOF){
        int lst=0;
        for(lst=0;prime[lst]<=n;lst++);
        printf("%d %d:",n,c);
        if(lst%2==0){
            int indx=max(0,(lst/2)-c);
            for(int i=indx;i<=indx+2*c-1&& i<lst;i++){
                printf(" %d",prime[i]);
            }
            printf("\n");
        }else{
            int indx=max(0,(lst/2)-c+1);
            for(int i=indx;i<=indx+2*c-2 && i<lst;i++){
                printf(" %d",prime[i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
