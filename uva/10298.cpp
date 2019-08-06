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
bool isvowel(char n)
{
    if(n=='a'||n=='e'||n=='i'||n=='o'||n=='u') return true;
    return false;
}
int power(int n,int p)
{
	if(p==0) return 1;
	if(p==1) return n;
	if(p&1){
		return n*(n,p-1);
	}
	int re=power(n,p/2);
	return re*re;
}
int lcm(int a,int b)
{
	return (a/__gcd(a,b))*b;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a;
    while(cin>>a && a!="."){
        for(int i=1;i<=a.size();i++) if(a.size()%i==0)
        {
            bool ok=1;
            string p=a.substr(0,i),q;
            for(int j=i;j+i<=a.size();j+=i){
                q=a.substr(j,i);
                if(p!=q){
                    ok=0;
                    break;
                }
            }
            if(ok){
                printf("%d\n",a.size()/i);
                break;
            }
        }
    }
}
