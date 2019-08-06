#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+7;
int check_dif(string a,string b)
{
    if(a.size()!=b.size()){
        return INF;
    }
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    return cnt;
}

int bfs(int s,int d,vector<int>G[])
{
    int level[210];
    memset(level,-1,sizeof(level));
    level[s]=0;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(level[v]==-1){
                Q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
    return level[d];
}
int main()
{
    int t,flag=0;
    cin>>t;
    while(t--){
        if(flag){
            cout<<'\n';
        }
        flag=1;
        string str;
        vector<string>w;
        while(cin>>str){
            if(str=="*"){
                break;
            }
            w.push_back(str);
        }
        int d=0,node=1;
        map<string,int>mp;
        vector<int>G[210];
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w.size();j++){
                d=check_dif(w[i],w[j]);
                if(d==1){
                    if(mp[w[i]]==0){
                        mp[w[i]]=node;
                        node++;
                    }
                    if(mp[w[j]]==0){
                        mp[w[j]]=node;
                        node++;
                    }
                    int u=mp[w[i]],v=mp[w[j]];
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
            }
        }
        string a,b,c;
        getline(cin,c);
        while(getline(cin,c)){
            if(c.size()==0){
                break;
            }
            int k;
            a="",b="";
            for(k=0;c[k]!=' ';k++){
                a+=c[k];
            }
            k++;
            for(;c[k];k++){
                b+=c[k];
            }
            cout<<a<<' '<<b<<' '<<bfs(mp[a],mp[b],G)<<endl;
        }
    }
}
