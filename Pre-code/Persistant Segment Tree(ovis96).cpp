/*input
7 3
8 9 10 11 12 13 14
2 5 3
4 4 1
1 7 3
*/

#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct Node{
	int l, r, sum;
	Node(){l = r = sum = 0;}
} tree[mx * 20];
int totNode = 0;

int update(int node, int b, int e, int i, int val)
{
	// cout << "hi 546"<< endl;
	int cur = ++totNode;
	int mid = (b+e)/2;
	if(b==e){
		tree[cur].sum = tree[node].sum + val;
		return cur;
	}
	if(i<=mid)
	{
		tree[cur].l = update(tree[node].l, b, mid, i, val);
		tree[cur].r = tree[node].r;
	}
	else{
		tree[cur].r = update(tree[node].r, mid+1, e, i, val);
		tree[cur].l = tree[node].l;
	}
	tree[cur].sum = tree[tree[cur].l].sum + tree[tree[cur].r].sum;
	return cur;
}

int query(int l, int r, int b, int e, int k)
{
	if(e-b+1 == k) return e;
	int mid = (b+e)/2;
	int left = tree[ tree[r].l ].sum - tree[ tree[l].l ].sum;
	if(left >= k)
		return query(tree[l].l, tree[r].l, b, mid, k);
	else return query(tree[l].r, tree[r].r, mid+1, e, k - left);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[n+1];
    set<int> st;
    for(int i = 0; i<n; i++){
    	scanf("%d", &a[i]);
    	st.insert(a[i]);
    }
    map<int, int> mp;
    int pos = 1;
    for(int x : st){
    	mp[x] = pos;
    	b[pos++] = x;
    }
    int root[n+1];
    root[0] = 0;
    for(int i = 0; i<n; i++){
    	root[i+1] = update(root[i], 1, n, mp[a[i]], +1);
    }

    while(m--)
    {
    	int l, r, k;
    	scanf("%d %d %d", &l, &r, &k);
    	printf("%d\n", b[query(root[l-1], root[r], 1, n, k)]);
    }
	return 0;
}
