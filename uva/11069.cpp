#include <bits/stdc++.h>
using namespace std;
const int oo=(1<<28);

int n;

int dp[80];

int solve(int cur)
{
    if(cur>n+1){
        return 0;
    }
    if(cur==n+1 || cur==n) return 1;


    return solve(cur+2)+solve(cur+3);
}


int main() {
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=76;i++){
        dp[i]=dp[i-2]+dp[i-3];
    }

    while(cin>>n){
        cout<<dp[n]<<endl;
    }    
}
