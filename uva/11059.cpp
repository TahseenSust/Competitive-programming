#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


int main()
{
    //freopen("uva.txt","w",stdout);
    int n,tc=0;
    while(cin>>n){
        ll s[200];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }

        ll ans=0,pro;

        for(int i=0;i<n;i++){
            pro=s[i];
            ans=max(ans,pro);
            for(int j=i+1;j<n;j++){
                pro*=s[j];
                ans=max(ans,pro);
            }
            ans=max(ans,pro);
        }
        printf("Case #%d: The maximum product is %lld.\n\n",++tc,ans);
    }
}
