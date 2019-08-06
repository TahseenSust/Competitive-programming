#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,tc=1;

    while(cin>>n && n){
        int ara[n+5];

        for(int i=0;i<n;i++){
            cin>>ara[i];
        }
        int ans=0;
        sort(ara,ara+n);
        for(int i=0;i<n;i++){
            ans+=n-(upper_bound(ara,ara+n,ara[i])-ara);
        }
        printf("Case %d: %d\n",tc++,ans);
    }
}
