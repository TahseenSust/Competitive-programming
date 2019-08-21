#include<bits/stdc++.h>
using namespace std;
#define mid (s+e)/2
#define root 0
#define N 30005
#define LN 20

vector <int> adj[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N], cost[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];
int st[N*6], qt[N*6];


void init()
{
    for(int i=0;i<N;i++) adj[i].clear();
    memset(baseArray,0,sizeof baseArray);
    memset(chainInd,0,sizeof chainInd);
    memset(chainHead,-1,sizeof chainHead);
    memset(posInBase,0,sizeof posInBase);
    memset(depth,0,sizeof posInBase);
    memset(otherEnd,0,sizeof posInBase);
    memset(subsize,0,sizeof posInBase);
    memset(pa,0,sizeof pa);
    memset(st,0,sizeof st);
    ptr=1;
}


void make_tree(int cur, int s, int e) {
	if(s == e) {
		st[cur] = baseArray[s];
		return;
	}
	make_tree(cur*2, s, mid);
	make_tree(cur*2+1, mid+1, e);
	st[cur] = st[cur*2] + st[cur*2+1];
}


void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e < x) return;
	if(s == e) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1 + 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m+1, e, x, val);
	st[cur] = st[c1] + st[c2];
}

int query_tree(int cur, int s, int e, int S, int E) {
	if(s > E || e < S) {
		return 0;
	}
	if(s >= S && e <= E) {
		return st[cur];
	}
	return query_tree(cur*2, s, mid, S, E)+query_tree(cur*2+1, mid+1, e, S, E);
}


int query_up(int u, int v) {
	int uchain, vchain = chainInd[v], ans = 0;
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			ans+=query_tree(1, 1, ptr, posInBase[v], posInBase[u]);
			break;
		}
		ans+=query_tree(1, 1, ptr, posInBase[chainHead[uchain]], posInBase[u]);
		u = chainHead[uchain];
		u = pa[0][u];
	}
	return ans;
}

int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

void query(int u, int v) {
	int lca = LCA(u, v);
	int ans = query_up(u, lca)+query_up(v,lca)-query_tree(1, 1, ptr, posInBase[lca], posInBase[lca]);
	printf("%d\n", ans);
}

void change(int u, int val) {
	update_tree(1, 1, ptr, posInBase[u], val);
}


void HLD(int curNode, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode;
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr;
	baseArray[ptr] = cost[curNode];
	ptr++;

	int sc = -1;
	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
		}
	}

	if(sc != -1) {
		HLD(sc, curNode);
	}

	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			chainNo++;
			HLD(adj[curNode][i], curNode);
		}
	}
}


void dfs(int cur, int prev, int _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(int i=0; i<adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,u,v,t;

    scanf("%d",&t);

    for(int tc=1;tc<=t;tc++){

        init();
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&cost[i]);
        }
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        chainNo = 1;
        dfs(root, -1);
        HLD(root,  -1);

        make_tree(1, 1, ptr);

        for(int i=1; i<LN; i++)
            for(int j=0; j<n; j++)
                if(pa[i-1][j] != -1)
                    pa[i][j] = pa[i-1][pa[i-1][j]];


        int q,a,b,c;

        scanf("%d",&q);

        printf("Case %d:\n",tc);

        while(q--){
            scanf("%d%d%d",&a,&b,&c);
            if(a==0){
                query(b,c);
            }else{
                change(b,c);
            }
        }
    }
}
