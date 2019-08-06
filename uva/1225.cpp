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
	int t;
	cin>>t;
	while(t--){
        string str;
        int n,cnt[10]={0};
        cin>>n;
        for(int i=1;i<=n;i++){
            int k=i;
            while(k){
                str+=((k%10)+'0');
                k/=10;
            }
        }
        for(int i=0;i<str.size();i++){
            cnt[str[i]-'0']++;
        }
        cout<<cnt[0];
        for(int i=1;i<10;i++){
            cout<<' '<<cnt[i];
        }
        cout<<endl;
	}
}
