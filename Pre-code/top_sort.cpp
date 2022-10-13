
cin>>n>>m;

for(int i=0;i<m;i++){
    cin>>u>>v;
    G[u].push_back(v);
    vis[v]++;
}
// vis represent indegree of a node
vector<int>st;
queue<int>Q;
for(int i=1;i<=n;i++){
    if(vis[i]==0){
        Q.push(i);
    }
}
while(!Q.empty()){
    int u=Q.front();
    Q.pop();
    st.push_back(u);

    for(auto v:G[u]){
        vis[v]--;
        if(vis[v]==0){
            Q.push(v);
        }
    }
}

if(st.size()!=n){
    printf("No solution\n");
}else{
    printf("%d",st[0]);
    for (int i = 1; i < (int)st.size(); ++i) printf(" %d", st[i]);
    printf("\n");
}
