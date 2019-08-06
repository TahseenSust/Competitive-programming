#include<bits/stdc++.h>
using namespace std;

#define mid (b+e)/2

typedef long long ll;

const int sz=250000;

struct dt
{
    ll a=0,b=0,d=0,c=0;
    bool flag=0,u3=0;
}lazy[sz*4];

void reset(int node)
{
    lazy[node].flag=0;
    lazy[node].a=0;
    lazy[node].b=0;
    lazy[node].d=0;
    lazy[node].c=0;
    lazy[node].u3=0;
}

ll tree[4*sz];

void propagate(int node,int b,int e)
{
    if(lazy[node].u3){
        tree[node]=(e-b+1)*lazy[node].c;
        if(b!=e){
            reset(node*2);
            reset(node*2+1);
            lazy[node*2].flag=lazy[node*2].u3=1;
            lazy[node*2+1].flag=lazy[node*2+1].u3=1;
            lazy[node*2].c=lazy[node*2+1].c=lazy[node].c;
        }
    }

    ll k=(e-b+1);
    tree[node]+=k*lazy[node].d+(lazy[node].a+lazy[node].b)*((k*(k+1))/2);

    if(b!=e){
        lazy[node*2].flag=1;
        lazy[node*2].a+=lazy[node].a;
        lazy[node*2].b+=lazy[node].b;

        lazy[node*2].d+=(e-mid)*lazy[node].b+lazy[node].d;
        
        lazy[node*2+1].flag=1;
        lazy[node*2+1].a+=lazy[node].a;
        lazy[node*2+1].b+=lazy[node].b;

        lazy[node*2+1].d+=(mid-b+1)*lazy[node].a+lazy[node].d;
        
    }

    reset(node);
}


void update1(int l,int r,int node=1,int b=1,int e=sz)
{
    if(lazy[node].flag){
        propagate(node,b,e);
    }
    if(b>r || e<l) return;
    if(b>=l && e<=r){
        ll m=(b-l+1);

        tree[node]+=((e-b+1)*(m+m+(e-b)))/2;

        if(b!=e){
            lazy[2*node].flag=1;
            lazy[2*node].a++;
            lazy[2*node].d+=(b-l);

            lazy[2*node+1].flag=1;
            lazy[2*node+1].a++;
            lazy[2*node+1].d+=(mid+1-l);

        }
        return;
    }
    update1(l,r,node*2,b,mid);
    update1(l,r,node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update2(int l,int r,int node=1,int b=1,int e=sz)
{
    if(lazy[node].flag){
        propagate(node,b,e);
    }
    if(b>r || e<l) return;
    if(b>=l && e<=r){
        ll m=(r-e+1);
        tree[node]+=((e-b+1)*(m+m+(e-b)))/2;
        if(b!=e){
            lazy[2*node].flag=1;
            lazy[2*node].b++;
            lazy[2*node].d+=(r-mid);

            lazy[2*node+1].flag=1;
            lazy[2*node+1].b++;
            lazy[2*node+1].d+=(r-e);
        }
        return;
    }
    update2(l,r,node*2,b,mid);
    update2(l,r,node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update3(int l,int r,ll val,int node=1,int b=1,int e=sz)
{
    if(lazy[node].flag){
        propagate(node,b,e);
    }
    if(b>r || e<l) return;
    if(b>=l && e<=r){
        ll m=(b-l+1);
        tree[node]=((e-b+1)*val);
        if(b!=e){
            reset(node*2);
            reset(node*2+1);
            lazy[node*2].flag=lazy[node*2].u3=1;
            lazy[node*2+1].flag=lazy[node*2+1].u3=1;
            lazy[node*2].c=val;
            lazy[node*2+1].c=val;
        }
        return;
    }
    update3(l,r,val,node*2,b,mid);
    update3(l,r,val,node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int l,int r,int node=1,int b=1,int e=sz)
{
    if(lazy[node].flag){
        propagate(node,b,e);
    }
    if(b>r || e<l) return 0;
    if(b>=l && e<=r){
        return tree[node];
    }
    return query(l,r,node*2,b,mid)+query(l,r,node*2+1,mid+1,e);
}





int main()
{
    int q,l,r,t;
    ll x;
    char c;
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
    scanf("%d",&q);
    while(q--){
        scanf("%*c%c",&c);
        if(c=='A'){
            scanf("%d%d",&l,&r);
            update1(l,r);
        }else if(c=='B'){
            scanf("%d%d",&l,&r);
            update2(l,r);
        }else if(c=='C'){
            scanf("%d%d%lld",&l,&r,&x);
            update3(l,r,x);
        }else{
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(l,r) );
        }
    }
}
