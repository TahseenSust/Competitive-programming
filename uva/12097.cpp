#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define PI acos(-1)
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

double a[100005];
int n,f;


int check(double mid)
{
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=floor(a[i]/mid);
	}
	return cnt;
}


int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>f;
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]=PI*a[i]*a[i];
		}
		double lo=0,hi=1e9;
		for(int i=0;i<100;i++){
			double mid=(lo+hi)/2;
			if(check(mid)<=f){
				hi=mid;
			}else{
				lo=mid;
			}
		}
		cout<<setprecision(4)<<fixed<<hi<<endl;
	}
}
