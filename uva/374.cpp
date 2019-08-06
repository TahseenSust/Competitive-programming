#include<bits/stdc++.h>
using namespace std;
int bigmod(int n,int p,int mod)
{
    if(p==0)
        return 1;
    if(p%2==0){
        int ret=bigmod(n,p/2,mod);
        return ((ret%mod)*(ret%mod))%mod;
    }else{
        return ((n%mod)*(bigmod(n,p-1,mod)%mod))%mod;
    }
}
int main()
{
	int n,p,mod;
	while(cin>>n>>p>>mod){
        cout<<bigmod(n,p,mod)<<endl;
	}
}
