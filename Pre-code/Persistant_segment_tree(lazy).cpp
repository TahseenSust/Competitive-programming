#include <bits/stdc++.h>
using namespace std;
#define maxn 100100
struct xjy
{
    int left ;
    int right;
    long long int flag;
    long long int sum;
};
xjy tree[maxn*30];
int T[maxn];
long long int a[maxn];
int n,m;
int tot;
long long int ans;
int build(int left,int right)
{
    int root=tot++;
    if(left==right)
    {
        tree[root].sum=a[left];
        tree[root].flag=0;
        return root;
    }
    int mid=(left+right)>>1;
    tree[root].left=build(left,mid);
    tree[root].right=build(mid+1,right);
    tree[root].sum=tree[tree[root].left].sum+tree[tree[root].right].sum;
    return root;
}
long long int update(int root,int left,int right,int l,int r,int val)
{
    int now=tot++;
    tree[now].sum=tree[root].sum;
    tree[now].left=tree[root].left;
    tree[now].right=tree[root].right;
    tree[now].flag=tree[root].flag;
    tree[now].sum+=(long long int )(right-left+1)*(long long int )val;
    if(left==l&&right==r)
    {
        tree[now].flag+=(long long int )val;
        return now;
    }
    int mid=(l+r)>>1;
    if(right<=mid)
    {
        tree[now].right=tree[root].right;
        tree[now].left=update(tree[root].left,left,right,l,mid,val);
    }
    else if(left>mid)
    {
        tree[now].left=tree[root].left;
        tree[now].right=update(tree[root].right,left,right,mid+1,r,val);
    }
    else
    {
        tree[now].left=update(tree[root].left,left,mid,l,mid,val);
        tree[now].right=update(tree[root].right,mid+1,right,mid+1,r,val);
    }
    return now;
}

void query(int root,int left,int right,int l,int r)
{
    if(left==l&&right==r)
    {
        ans+=tree[root].sum;
        return ;
    }
    ans+=tree[root].flag*(long long int )(right-left+1);
    int mid=(l+r)>>1;
    if(right<=mid)
    {
        query(tree[root].left,left,right,l,mid);
    }
    else if(left>mid)
    {
        query(tree[root].right,left,right,mid+1,r);
    }
    else
    {
        query(tree[root].left,left,mid,l,mid);
        query(tree[root].right,mid+1,right,mid+1,r);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int time=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        T[time]=build(1,n);
        for(int i=1;i<=m;i++)
        {
            char c;
            scanf(" %c",&c);
            if(c=='Q')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                ans=0;
                query(T[time],l,r,1,n);
                printf("%lld\n",ans);
            }
            else if(c=='C')
            {
                int l,r,val;
                scanf("%d%d%lld",&l,&r,&val);
                time++;
                T[time]=update(T[time-1],l,r,1,n,val);
            }
            else if(c=='H')
            {
                int l,r,t;
                scanf("%d%d%d",&l,&r,&t);
                ans=0;
                query(T[t],l,r,1,n);
                printf("%lld\n",ans);
            }
            else
            {
                int t;
                scanf("%d",&t);
                time=t;
            }
        }
    }
}
