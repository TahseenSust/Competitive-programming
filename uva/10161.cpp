#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool is_per(ll a)
{
    return ((ll)sqrt(a)*(ll)sqrt(a)==a);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll t,x,y;
    while(cin>>t && t){
        double a,b;
        ll A;
        a=sqrt(t);
        if(is_per(t)){
            if((ll)a&1){
                x=1; y=a;
            }else{
                x=a; y=1;
            }
        }else{
            a=round(a);
            A=a*a;
            ll b=a;
            if((ll)b&1){
                if(t>A){
                    x=t-A; y=b+1;
                }else{
                    x=1+A-t; y=b;
                }
            }else{
                if(t>A){
                    x=b+1; y=t-A;
                }else{
                    x=b; y=1+A-t;
                }
            }
        }
        cout<<x<<' '<<y<<endl;
    }
}
