#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



struct segmentTree
{
	vector<ll>ara;
	vector<ll>tree;
	vector<ll>lazy;
	int n;

	segmentTree(int n,vector<ll>&a) : ara(n+1), tree(4*n, 0), lazy(4*n, 0), n(n) {
		for(int i=0;i<n;i++){
			ara[i+1]=a[i];
		}
	}

	void build(){
		build(1,1,n);
	}

	void build(int node,int b,int e)
	{
	    if(b==e){
	        tree[node]=ara[b];
	        return;
	    }
	    int mid=(b+e)/2;
	    build(node*2,b,mid);
	    build(node*2+1,mid+1,e);
	    tree[node]=tree[node*2]+tree[node*2+1];
	}

	void propagate(int node,int b,int e)
	{
	    tree[node]+=lazy[node]*(e-b+1);
	    flush(node,b,e);
	}
	void flush(int node,int b,int e){
		if(b!=e){
	        lazy[node*2]+=lazy[node];
	        lazy[node*2+1]+=lazy[node];
	    }
	    lazy[node]=0ll;
	}

	void update(int i,ll val){ // point update
		update(1,1,n,i,i,val);
	}

	void update(int l,int r,ll val){ // range update
		update(1,1,n,l,r,val);
	}

	void update(int node,int b,int e,int l,int r,ll val)
	{
	    propagate(node,b,e);
	    if(b>r || e<l) return;
	    if(b>=l && e<=r){
	        tree[node]+=val*(e-b+1);
	        lazy[node]+=val;
	        flush(node,b,e);
	        return;
	    }
	    int mid=(b+e)/2;
	    update(node*2,b,mid,l,r,val);
	    update(node*2+1,mid+1,e,l,r,val);
	    tree[node]=tree[node*2]+tree[node*2+1];
	}

	ll query(int l,int r)
	{
		return query(1,1,n,l,r);
	}

	ll query(int node,int b,int e,int l,int r)
	{
	    propagate(node,b,e);
	    if(b>r || e<l) return 0ll;
	    if(b>=l && e<=r) return tree[node];
	    int mid=(b+e)/2;
	    return query(node*2,b,mid,l,r)+query(node*2+1,mid+1,e,l,r);
	}
};





int main()
{
    //freopen("input.txt","r",stdin);
    int n,q;

    cin>>n>>q;

    vector<ll>ara(n,0); 

    for(int i=0;i<n;i++){
        cin>>ara[i];
    }


    segmentTree tree(n,ara);

    tree.build();

    while(q--){
        char ch;
        int l,r;
        ll v;
        cin>>ch;
        if(ch=='C'){
            cin>>l>>r>>v;
            tree.update(l,r,v);
        }else{
            cin>>l>>r;
            printf("%lld\n",tree.query(l,r));
        }
    }

}
