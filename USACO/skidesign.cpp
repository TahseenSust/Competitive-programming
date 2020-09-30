/*
ID: tahseen1
PROG: skidesign
LANG: C++
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf

int main()
{
    ofstream cout ("skidesign.out");
    ifstream cin ("skidesign.in");
	int n,x,k=0; cin>>n;
	int ara[n+5];
	map<int,int>mp; mp.clear();
	for(int i=0;i<n;i++){
        cin>>ara[i];
	}
	ll ans=INT_MAX;
	for(int i=1;i<=83;i++){
        ll tmp=0;
        for(int j=0;j<n;j++){
            if(ara[j]<i){
                tmp+=(i-ara[j])*(i-ara[j]);
            }else if(ara[j]>i+17){
                tmp+=(ara[j]-i-17)*(ara[j]-i-17);
            }
        }
        ans=min(ans,tmp);
	}
	cout<<ans<<endl;
}
