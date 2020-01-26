#include<bits/stdc++.h>
using namespace std;

int n,len[25],sum,tt=1;

int dp[6][(1<<20)+5];
int casio[6][(1<<20)+5];

int mask_sum(int mask)
{
    int tot=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            tot+=len[i];
        }
    }
    return tot;
}


int solve(int id,int mask)
{
    if(id>4){
        return mask==((1<<n)-1);
    }

    int &ret=dp[id][mask];

    if(casio[id][mask]==tt){
        return ret;
    }
    casio[id][mask]=tt;

    ret=0;

    for(int i=0;i<n && !ret;i++){
        if(mask&(1<<i)) continue;
        if(id*sum-mask_sum(mask)-len[i]>=0){
            ret|=solve(id+(id*sum-mask_sum(mask)-len[i]==0),mask|(1<<i));
        }
    }

    return ret;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&len[i]);
            sum+=len[i];
        }

        if(sum%4!=0){
            printf("no\n");
        }else{
            sum/=4;
            sort(len,len+n);
            if(solve(1,0)){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
        tt++;
    }
}
