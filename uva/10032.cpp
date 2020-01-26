#include<bits/stdc++.h>
using namespace std;

long long dp[45005];
int main()
{
    int n,arr[102],sum,t;

    cin>>t;


    while(t--){

        cin>>n;
        sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }

        memset(dp,0,sizeof dp);
        dp[0]=1ll;

        for(int i=0;i<n;i++){
            for(int w=sum/2;w>=arr[i];w--){
                dp[w]|=dp[w-arr[i]]<<(1ll);
            }
        }

        int sum1=0,sum2=0;

        for(int w=sum/2;w>0;w--){
            if(dp[w]&(1ll<<(n/2))){
                sum1=w;
                break;
            }
            if(n&1 && dp[w]&(1ll<<((n+1)/2))){
                sum1=w;
                break;
            }
        }
        cout<<sum1<<' '<<sum-sum1<<endl;
    }
}
