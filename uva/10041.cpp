#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;
        vector<int>vec;
        cin>>n;
        vec.resize(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        int ans=INT_MAX,sum;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<n;j++){
                sum+=abs(vec[i]-vec[j]);
            }
            ans=min(ans,sum);
        }
        cout<<ans<<endl;
    }
}
