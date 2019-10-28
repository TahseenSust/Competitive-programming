const int N = int(1e5)+10;
const int M = int(5e5)+10;
VI g[N];
VI tree[N],rg[N],bucket[N];
int sdom[N],par[N],dom[N],dsu[N],label[N];
int arr[N],rev[N],T;
LL ans;
int Find(int u,int x=0)
{
	if(u==dsu[u])return x?-1:u;
	int v = Find(dsu[u],x+1);
	if(v<0)return u;
	if(sdom[label[dsu[u]]] < sdom[label[u]])
		label[u] = label[dsu[u]];
	dsu[u] = v;
	return x?v:label[u];
}
void Union(int u,int v) //Add an edge u-->v
{
	dsu[v]=u; 	//yup,its correct :)
}
void dfs0(int u)
{
	T++;arr[u]=T;rev[T]=u;
	label[T]=T;sdom[T]=T;dsu[T]=T;
	for(int i=0;i<SZ(g[u]);i++)
	{
		int w = g[u][i];
		if(!arr[w])dfs0(w),par[arr[w]]=arr[u];
		rg[arr[w]].PB(arr[u]);
	}
}
int dfs(int u,int p)
{
	int ret=1;
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(w==p)continue;
		int x = dfs(w,u);
		if(u==1)ans -= (x*1ll*(x-1ll))/2ll;
		ret+=x;
	}
	return ret;
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		si(u);si(v);
		g[u].PB(v);
	}
	//Build Dominator tree
	dfs0(1);
	n=T;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<SZ(rg[i]);j++)
			sdom[i] = min(sdom[i],sdom[Find(rg[i][j])]);
		if(i>1)bucket[sdom[i]].PB(i);
		for(int j=0;j<SZ(bucket[i]);j++)
		{
			int w = bucket[i][j];
			int v = Find(w);
			if(sdom[v]==sdom[w])dom[w]=sdom[w];
			else dom[w] = v;
		}
		if(i>1)Union(par[i],i);
	}
	for(int i=2;i<=n;i++)
	{
		if(dom[i]!=sdom[i])
			dom[i]=dom[dom[i]];
		tree[rev[i]].PB(rev[dom[i]]);
		tree[rev[dom[i]]].PB(rev[i]);
	}
	//done :) 
	ans = (n*1ll*(n-1ll))/2ll;
	dfs(1,1);
	lldout(ans);
	return 0;
}
