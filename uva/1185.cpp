#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ans;
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            ans=ans+log10((double)i);

        }
        ans=floor(ans)+1;
        printf("%.lf\n",ans);
    }
}
