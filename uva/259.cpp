#include<bits/stdc++.h>
using namespace std;
const int INF=100000000;
int n=40;
int capacity[109][109];
vector<int>G[109];
int bfs(int s,int t,vector<int>&parent)
{
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,int> >Q;
    Q.push({s,INF});
    while(!Q.empty()){
        int cur=Q.front().first;
        int flow=Q.front().second;
        Q.pop();
        for(int i=0;i<G[cur].size();i++){
            int next=G[cur][i];
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next]=cur;
                int new_flow=min(flow,capacity[cur][next]);
                if(next==t){
                    return new_flow;
                }
                Q.push({next,new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s,int t)
{
    int flow=0;
    vector<int>parent(n+5);
    int new_flow;
    while(new_flow=bfs(s,t,parent)){
        flow+=new_flow;
        int cur=t;
        while(cur!=s){
            int prev=parent[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string st;
    map<char,int>mp;
    for(int i=0;i<26;i++){
        mp['A'+i]=i+1;
    }
    for(int i=27;i<37;i++){
        mp[(char)('0'+i-27)]=i;
    }
    while(getline(cin,st)){

        int total=0;
        int u=mp[st[0]];
        int cost=st[1]-'0';
        total+=cost;
        G[0].push_back(u);
        capacity[0][u]=cost;
        int i=3;
        while(st[i]!=';'){
            int v=mp[st[i]];
            //cout<<v<<endl;
            G[u].push_back(v);
            G[v].push_back(u);
            capacity[u][v]=INF;
            G[v].push_back(37);
            capacity[v][37]=1;
            i++;
        }
        while(getline(cin,st)){
            if(st.size()==0){
                break;
            }
            int u=mp[st[0]];
            int cost=st[1]-'0';
            total+=cost;
            G[0].push_back(u);
            capacity[0][u]=cost;
            int i=3;
            while(st[i]!=';'){
                int v=mp[st[i]];
                //cout<<v<<endl;
                G[u].push_back(v);
                G[v].push_back(u);
                capacity[u][v]=INF;
                G[v].push_back(37);
                capacity[v][37]=1;
                i++;
            }
        }
        int flow=maxflow(0,37);

        if(flow!=total){
            cout<<"!\n";
        }else{
            for(int i='0';i<='9';i++){
                bool flag=0;
                for(int j='A';j<='Z';j++){
                    int u=mp[(char)i],v=mp[(char)j];
                    if(capacity[u][v]==1){
                        flag=1;
                        cout<<(char)j;
                        break;
                    }
                }
                if(!flag){
                    cout<<"_";
                }
            }
            cout<<endl;
        }
        memset(capacity,0,sizeof capacity);
        for(int i=0;i<100;i++){
            G[i].clear();
        }
    }
}
/**
A4 01234;
Q1 5;
P4 56789;

A4 01234;
Q1 5;
P5 56789;
*/
