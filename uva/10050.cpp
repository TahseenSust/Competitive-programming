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
#define DBG pf("ok\n");
bool isvowel(char n)
{
    if(n=='a'||n=='e'||n=='i'||n=='o'||n=='u') return true;
    return false;
}
int power(int n,int p)
{
	int res=1;
	for(int i=0;i<p;i++){
		res*=n;
	}
	return res;
}
int main()
{
	ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int d,pa,x,ans=0;
        bool days[4000]={0};
        cin>>d>>pa;
        for(int i=0;i<pa;i++){
            cin>>x;
            int j=0;
            while(j<=d){
                j=j+x;
                if((j%7)%6!=0&&j%7!=0&&days[j]==0&&j<=d){
                    ans++;
                }
                days[j]=1;
            }
        }
        cout<<ans<<endl;
    }
}

