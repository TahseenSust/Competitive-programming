#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bigmod(ll n,ll p)
{
    if(p==0){
        return 1%1000;
    }
    if(p==1){
        return n%1000;
    }
    ll re=bigmod(n,p/2)%1000;
    re=(re%1000)*(re%1000);
    re%=1000;
    if(p&1){
        re=(re%1000)*(n%1000);
        re%=1000;
    }
    return re%1000;

}

int main()
{
    //freopen("uva.txt","w",stdout);


    ll n,k;
    int t;
    cin>>t;

    for(int tc=1;tc<=t;tc++){
        cin>>n>>k;
        double l=k*log10(n);
        l-=(ll)l;

        double ans1=pow(10,l)*100;

        ll ans2=bigmod(n,k);
        printf("%lld...",(ll)ans1);
        for(int i=(ll)ceil(log10((double)ans2+1));i<3;i++){
            printf("0");
        }
        if(ans2!=0)
            printf("%lld",ans2);
        cout<<endl;
    }
}
