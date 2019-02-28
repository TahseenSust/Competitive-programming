#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

ost st;

int search(int x)
{
	int l=0,r=1e9+5,m;

	while(l<r){
		m=(l+r)/2;
		if(m-st.order_of_key(m+1)<x){
			l=m+1;
		}else{
			r=m;
		}
	}
	return l;
}

int main()
{

    int n,m,x,sz=0;
    char ch;

    cin>>n>>m;

    while(m--){
    	cin>>ch>>x;
    	x=search(x);
    	if(ch=='L'){
    		cout<<x<<endl;
    	}else{
    		st.insert(x);
    	}
    }
    

    return 0;
}
