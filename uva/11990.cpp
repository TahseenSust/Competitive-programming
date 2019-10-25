#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;


const int sz=200500;

ost mst[sz];
int bit[sz];
int ara[sz],n,q;

void init()
{
    memset(bit,0,sizeof bit);
    for(int i=0;i<sz;i++){
        mst[i].clear();
    }
}

void update(int x, int delta)
{
      for(; x <= n; x += x&-x){
        mst[x].insert(delta);
        bit[x]++;
      }
}

void update2(int x, int delta)
{
      for(; x <= n; x += x&-x){
        mst[x].erase(delta);
        bit[x]--;
      }
}


int sum(int x)
{
    int re = 0;
    for(; x > 0; x -= x&-x)
        re += bit[x];
    return re;
}

int query(int x,int delta)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += mst[x].order_of_key(delta);
     return sum;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(scanf("%d%d",&n,&q)!=EOF){

        init();

        long long total=0;
        int pos[sz];


        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
            update(i,ara[i]);
            pos[ara[i]]=i;
        }

        for(int i=1;i<=n;i++){
            total+=(i-1-query(i,ara[i]));
        }

        int del;

        while(q--){
            scanf("%d",&del);
            printf("%lld\n",total);
            int boro=sum(pos[del]-1)-query(pos[del],del);
            int suto=query(n,del)-query(pos[del],del);
            update2(pos[del],del);
            total-=(boro+suto);



        }

    }

}
