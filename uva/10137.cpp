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
    int n;
    double diff,total,avg,possum,negsum,ans;
    while(cin>>n && n){
        double m[n+5];
        total=avg=possum=negsum=0;
        for(int i=0;i<n;i++){
            scanf("%lf",&m[i]);
            total+=m[i];
        }
        avg=total/n;
        for(int i=0;i<n;i++){
            diff=(double)(long)((m[i]-avg)*100.0)/100.0;
            if(diff<0){
                negsum+=diff;
            }else{
                possum+=diff;
            }
        }
        ans=max(-1*negsum,possum);
        pf("$%.2lf\n",ans);
    }
}


