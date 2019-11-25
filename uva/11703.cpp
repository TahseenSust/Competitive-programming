#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1000000;

ll dp[1000005];

void solve()
{
    dp[0]=1;


    for(int i=1;i<=1000000;i++){
        double x=i*1.0;
        int sq=floor(x*1.0-sqrt(x*1.0));
        int ln=(int)floor(log2(x)/log2(exp(1)));
        int sn=floor(x*sin(x)*sin(x));
        dp[i]=(dp[sq]+dp[ln]+dp[sn])%mod;
    }

}

int main()
{
    solve();

    int n;

    while(cin>>n && n>=0){
        cout<<dp[n]<<endl;
    }
}
