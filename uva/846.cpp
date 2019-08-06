#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s,e;
    int T;
    scanf("%d",&T);

    while(T--){
        long long step=0,in=1;
        scanf("%lld%lld",&s,&e);
        if(s>e){
            int temp;
            temp=s;
            s=e;
            e=temp;
        }

        while(s<e){
            s=s+in;
            step++;
            if(s>=e){
                break;
            }
            e=e-in;
            step++;
            if(s>=e){
                break;
            }
            in++;

        }
        printf("%lld\n",step);
    }
}
