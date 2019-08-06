#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans=0,x,y,z;
        for(int i=0;i<n;i++){
            cin>>x>>y>>z;
            ans+=x*z;
        }
        cout<<ans<<endl;
    }
}

