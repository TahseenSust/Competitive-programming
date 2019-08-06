#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD=1000000000+7;
int n,m;
stack<int>st;

void dfs(int u,vector<int>G[],bool vis[])
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        if(vis[G[u][i]]==0){
            dfs(G[u][i],G,vis);
        }
    }
    st.push(u);
}

int main()
{
    //freopen("out.txt","w",stdout);
    string ss;
    vector<string>str;
    while(cin>>ss){
        if(ss=="#") break;
        str.push_back(ss);
    }
    vector<int>G[100];
    map<char,int>mp;
    for(int i=0;i<str.size()-1;i++){
        for(int j=0;j<min(str[i].size(),str[i+1].size());j++){
            if(str[i][j]!=str[i+1][j]){
                G[str[i][j]-'A'].push_back(str[i+1][j]-'A');
                break;
            }
        }
    }
    for(int i=0;i<str.size();i++){
        for(int j=0;j<str[i].size();j++)
            mp[str[i][j]]=1;
    }
    bool vis[100]={0};
    for(int i=0;i<26;i++){
        if(vis[i]==0){
            dfs(i,G,vis);
        }
    }
    while(!st.empty()){
        if(mp.find(st.top()+'A')!=mp.end())
            cout<<(char)(st.top()+'A');
        st.pop();
    }
    cout<<endl;

}
