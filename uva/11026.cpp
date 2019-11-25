#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1002];

int main()
{
    ll n,m,a[1002];

    while(scanf("%lld%lld",&n,&m)){

        if(n==0 && m==0) return 0;

        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        memset(dp,0,sizeof dp);
        dp[0]=1;

        ll sum=0;

        for(int i=n,k=1;i>=1;i--,k++){
            for(int j=k;j>=1;j--){
                dp[j]=(dp[j]+dp[j-1]*a[i])%m;
            }
        }

        for(int i=1;i<=n;i++){
            sum=max(sum,dp[i]);
        }

        printf("%lld\n",sum);
    }
}
