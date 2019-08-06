/**
--------- -    |   |  /--  ----- ----- |\   |
    |    / \   |___| /__   |___  |___  | \  |
    |   /---\  |   |    /  |     |     |  \ |
    |  /     \ |   | __/   |____ |____ |   \|
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	ll n,k;
	while(cin>>n>>k){
        ll ans=n;
        while(n>=k){
            ans+=(n/k);
            n=(n/k)+(n%k);
        }
        cout<<ans<<endl;
	}
}
