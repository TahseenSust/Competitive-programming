#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;

typedef tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> ost;


int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,k,mx=0,row=1,x,sz=0;
	
	cin>>n>>k;

	for(int i=1;i<=k;i++){
		int cur=0;
		ost X;
		for(int j=0;j<n;j++){
			cin>>x;
			cur+=X.order_of_key({x,++sz});
			X.insert({x,sz});
		}
		if(cur>mx){
			mx=cur;
			row=i;
		}
	}

	cout<<row<<endl;


}
