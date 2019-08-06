/*
Honesty is the best policy
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX=1000000000000000000ll;


int n,k;
ll len[35];

void all(int i,int cnt,ll cur,int limit,vector<ll>X[])
{
	if(i==limit){
		if(cnt<=k-1){
			X[cnt].push_back(cur);
		}
		return;
	}

	all(i+1,cnt,cur,limit,X);
	all(i+1,cnt+1,cur+len[i],limit,X);

}


int main()
{
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>k;

		for(int i=0;i<n;i++){
			cin>>len[i];
		}

		sort(len,len+n);

		vector<ll>X[35],Y[35];
		ll ans=0;
		for(int i=k-1;i<n;i++){
			int x=i;
			for(int j=0;j<=k;j++){
				X[j].clear();
				Y[j].clear();
			}
			all(0,0,0,x/2,X);
			all(x/2,0,0,x,Y);

			for(int j=0;j<=k-1;j++){
				int la=k-1-j;
				sort(Y[la].begin(),Y[la].end());
				Y[la].push_back(INT_MAX);
				for(int l=0;l<X[j].size();l++){
					ll s=(len[i]-X[j][l])+1;
					int indx=lower_bound(Y[la].begin(),Y[la].end(),s)-Y[la].begin();
					ans+=(Y[la].size()-1-indx);
				}
			}
		}
		printf("Case %d: %lld\n",tc,ans);
	}
}

