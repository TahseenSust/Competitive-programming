#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll n,p,cnt;

    while(cin>>n){

        p=1;
        cnt=0;

        while(p<n){
            if(!(cnt&1)){
                p*=9;
            }else{
                p*=2;
            }
            cnt++;
        }
        if(cnt&1){
            cout<<"Stan wins.\n";
        }else{
            cout<<"Ollie wins.\n";
        }
    }

}
