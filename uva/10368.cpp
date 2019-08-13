#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main()
{
    ll n,m;

    while(cin>>n>>m && n && m)
    {
        int cnt=0;
        while(1){
            if(n<m) swap(n,m);
            if(n%m==0 || (n/m)>1){
                break;
            }else{
                n%=m;
            }
            cnt^=1;
        }
        if(!cnt) cout<<"Stan wins\n";
        else cout<<"Ollie wins\n";
    }



}
