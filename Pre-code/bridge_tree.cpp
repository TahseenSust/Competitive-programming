vector<int> tree[N],g[N];//edge list representation of graph g[u].push_back(edge_no)
int U[M],V[M],vis[N],arr[N],T,dsu[N];
bool isbridge[M]; // if i'th edge is a bridge edge or not
int adj(int u,int e) {
    return U[e]^V[e]^u;
}
int f(int x) {
    return dsu[x]=(dsu[x]==x?x:f(dsu[x]));
}
void merge(int a,int b) {
    dsu[f(a)]=f(b);
}
int dfs0(int u,int edge) { //mark bridges
    vis[u]=1;
    arr[u]=T++;
    int dbe = arr[u];
    for(auto e : g[u]) {
        int w = adj(u,e);
        if(!vis[w])dbe = min(dbe,dfs0(w,e));
        else if(e!=edge)dbe = min(dbe,arr[w]);
    }
    if(dbe == arr[u] && edge!=-1)isbridge[edge]=true;
    else if(edge!=-1) merge(U[edge],V[edge]);
    return dbe;
}
void buildBridgeTree(int n,int m) {
    for(int i=1; i<=n; i++)dsu[i]=i;
    for(int i=1; i<=n; i++)if(!vis[i])dfs0(i,-1);
    for(int i=1; i<=m; i++)
        if(f(U[i])!=f(V[i])) {
            tree[f(U[i])].PB(f(V[i]));
            tree[f(V[i])].PB(f(U[i]));
        }
}
