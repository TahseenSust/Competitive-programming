#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool state[10000003];

int main()
{
    int n,m,mv[14];

    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<m;i++){
            scanf("%d",&mv[i]);
        }

        memset(state,0,sizeof state);

        state[0]=0;

        for(int i=1;i<=n;i++){
            state[0]=0;
            for(int j=0;j<m;j++){
                if(i-mv[j]>=0 && !state[i-mv[j]]){
                    state[i]=1;
                    break;
                }
            }
        }

        if(state[n]){
            printf("Stan wins\n");
        }else{
            printf("Ollie wins\n");
        }

    }



}
