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
	string num;
	int mod=131071,ans=0;
	e:
	while(cin>>num){
        ans*=2;
        ans%=mod;
        if(num[0]!='#')
            ans+=(num[0]-'0');
        for(int i=1;i<num.size() && num[i]!='#';i++){
            ans=ans*2;
            ans+=(num[i]-'0');
            ans%=mod;
        }
        if(num[num.size()-1]!='#'){
            goto e;
        }
        //cout<<ans<<endl;
        cout<<(ans%mod?"NO":"YES")<<endl;
        ans=0;
	}
}
