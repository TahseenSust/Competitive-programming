#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcdExt(ll a,ll b,ll *x,ll *y)
{
    if(a==0){
        *x=0;
        *y=1;
        return b;
    }

    ll x1,y1;
    ll gcd=gcdExt(b%a,a,&x1,&y1);

    *x = y1 -(b/a)*x1;
    *y = x1;

    return gcd;
}
int main()
{
    ll a,b,x,y;
    while(cin>>a>>b){
        ll g=gcdExt(a,b,&x,&y);
        if(a==b){
            x=0;
            y=1;
        }
        cout<<x<<' '<<y<<' '<<g<<endl;
    }
}
