#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


int main()
{
    //freopen("uva.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){

        int n,x,cnt=0,ans=0,l=0,r=0;
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>x;
            if(mp.find(x)==mp.end()){
                mp[x]=i;
            }else{
                l=max(l,mp[x]+1);
                mp[x]=i;
            }
            r++;
            //cout<<r<<' '<<l<<' '<<r-l<<endl;
            ans=max(ans,r-l);
        }
        cout<<ans<<endl;

    }
}
