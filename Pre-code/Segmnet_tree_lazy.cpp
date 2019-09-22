//#include <bits/stdc++.h>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits>
using namespace std;

#define INT_MAX 1<<30

typedef long long ll;


#define mid ((b+e)/2)

const int sz=100005;

ll tree[sz*4],lazy[sz*4];
ll ara[sz];

void build(int node,int b,int e)
{
    if(b==e){
        tree[node]=ara[b];
        return;
    }
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void propagate(int node,int b,int e)
{
    tree[node]+=lazy[node]*(e-b+1);
    if(b!=e){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0ll;
}



void update(int node,int b,int e,int l,int r,ll val)
{
    propagate(node,b,e);
    if(b>r || e<l) return;
    if(b>=l && e<=r){
        tree[node]+=val*(e-b+1);
        if(b!=e){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    update(node*2,b,mid,l,r,val);
    update(node*2+1,mid+1,e,l,r,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node,int b,int e,int l,int r)
{
    propagate(node,b,e);
    if(b>r || e<l) return 0ll;
    if(b>=l && e<=r) return tree[node];
    return query(node*2,b,mid,l,r)+query(node*2+1,mid+1,e,l,r);
}


int main()
{
    //freopen("input.txt","r",stdin);
    int n,q;

    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++){
        scanf("%lld",&ara[i]);
    }

    build(1,1,n);

    while(q--){
        char ch;
        int l,r;
        ll v;
        scanf(" %c",&ch);
        if(ch=='C'){
            scanf("%d%d%lld",&l,&r,&v);
            update(1,1,n,l,r,v);
        }else{
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,1,n,l,r));
        }
    }

}
