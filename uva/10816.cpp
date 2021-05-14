#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define EPS 1e-15
typedef long long ll;
typedef pair<int,int> pii;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost; // set
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset; // multiset
*/
// direction array
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
// Bitmask
/*
bool check(int mask,int pos){return mask&(1<<pos);}
int SET(int mask,int pos){return mask|(1<<pos);}
int FLIP(int mask,int pos){return mask^(1<<pos);}
int reset(int mask,int pos){return mask&~(1 << pos);}
*/




struct node
{
	int v;
	double r,d;
	node(){}
	node(int a,double b,double c){
		v=a;
		r=b;
		d=c;
	}
};
vector<node>G[200];

int n,e,s,t;


bool vis[200];
double dis[200];

bool compare(double a,double b)
{
	if(a<=b || (a>b && fabs(a-b)<=EPS)) return true;
	return false;
}

bool check(double mid)
{
	memset(vis,false,sizeof vis);
	queue<int>q;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==t){
			return true;
		}
		for(auto to:G[u]){
			if(vis[to.v]==false && compare(to.r,mid)){
				vis[to.v]=1;
				q.push(to.v);
			}
		}
	}
	return false;
}


int par[200];

void path(double mid)
{
	// cout<<setprecision(10)<<mid<<endl;
	priority_queue<pair<double,int>>pq;
	pq.push({0,s});
	for(int i=1;i<=n;i++) dis[i]=1e9;
	dis[s]=0;
	par[s]=-1;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(u==t){
			return;
		}
		for(auto to:G[u]){
			// printf("%.2lf %.2lf\n",to.v,mid);
			// cout<<setprecision(10)<<fixed<<to.r<<' '<<mid<<endl;
			// cout<<u<<' '<<to.v<<' '<<to.r<<' '<<(to.r<=mid || fabs(to.r-mid)<=EPS)<<' '<<(dis[u]+to.d<dis[to.v] || fabs(dis[u]+to.d-dis[to.v])<=EPS)<<endl;
			if(compare(to.r,mid) && compare(dis[u]+to.d,dis[to.v])){
				dis[to.v]=dis[u]+to.d;
				pq.push({-dis[to.v],to.v});
				 // cout<<u<<' '<<to.v<<endl;
				par[to.v]=u;
			}
		}
	}

}

int main()
{
	// int cnt=10;
	while(cin>>n>>e>>s>>t){
		// if(cnt==0) break;
		// cnt--;
		for(int i=0;i<e;i++){
			int x,y;
			double r,d;
			cin>>x>>y>>r>>d;
			G[x].push_back(node(y,r,d));
			G[y].push_back(node(x,r,d));
		}
		double lo=0,hi=1000;
		for(int i=0;i<100;i++){
			double mid=(lo+hi)/2;
			//cout<<check(mid)<<' '<<mid<<endl;
			if(check(mid)){
				hi=mid;
			}else{
				lo=mid;
			}
		}
		path(hi);
		int x=t;
		vector<int>ans;
		ans.push_back(t);
		 // cout<<par[t]<<endl;
		while(par[x]!=-1){
			ans.push_back(par[x]);
			x=par[x];
			// cout<<x<<endl;
		}
		reverse(ans.begin(),ans.end());
		cout<<ans[0];
		for(int i=1;i<ans.size();i++){
			cout<<' '<<ans[i];
		}
		cout<<endl;
		cout<<setprecision(1)<<fixed<<dis[t]<<' '<<(lo+hi)/2.0<<endl;
		memset(par,0,sizeof par);
		for(int i=1;i<=n;i++)
			G[i].clear();
	}
}
