#include<bits/stdc++.h>
using namespace std;
#define MX 1005
stack<int>st;
vector<int>compo[MX];
vector<int>G[MX];
vector<int>R[MX];
bool vis[MX];
int color[MX],n,mark;
void clear_kor()
{
    memset(vis,0,sizeof vis);
    memset(color,0,sizeof color);
    for(int i=0;i<MX;i++){
        R[i].clear();
        G[i].clear();
    }
}
void dfs(int u)
{
    color[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(color[v]==0){
            dfs(v);
        }
    }
    st.push(u);
}

void reverse_edge()
{
    for(int i=1;i<=n;i++){
        for(int j=0;j<G[i].size();j++){
            int v=G[i][j];
            R[v].push_back(i);
        }
    }
}

void dfs2(int u)
{
    vis[u]=1;
    for(int i=0;i<R[u].size();i++){
        int v=R[u][i];
        if(vis[v]==0){
            dfs2(v);
        }
    }
}
void find_scc()
{
    mark=0;
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            dfs(i);
        }
    }
    reverse_edge();
    int u;
    while(!st.empty()){
        u=st.top();
        st.pop();
        if(vis[u]==false){
            mark=mark+1;
            dfs2(u);
        }
    }
}
int main()
{
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int e,u,v,k;
    while(cin>>n>>e){
        if(n==0 && e==0){
            break;
        }
        clear_kor();
        string str,s1,s2;
        map<string,int>mp;
        getline(cin,str);
        for(int i=0;i<n;i++){
            getline(cin,str);
            mp[str]=i+1;
        }
        for(int i=0;i<e;i++){
            getline(cin,s1);
            getline(cin,s2);
            u=mp[s1];
            v=mp[s2];
            G[u].push_back(v);
            //R[v].push_back(u);
        }
        find_scc();
//        for(int i=1;i<=mark;i++){
//            for(int j=0;j<compo[i].size();j++){
//                cout<<compo[i][j]<<' ';
//            }
//            cout<<endl;
//        }
cout<<mark<<endl;
    }
}
