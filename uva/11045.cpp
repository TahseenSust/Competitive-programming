#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=(1<<28);
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int sz=105;
int capacity[sz][sz];
vector<int>G[sz];
int n,m;

int bfs(int s,int t,vector<int>&parent)
{
	fill(parent.begin(),parent.end(),-1);
	parent[s]=-2;
	queue<pair<int,int>>Q;
	Q.push({s,INF});

	while(!Q.empty()){
		int cur=Q.front().first;
		int flow=Q.front().second;
		Q.pop();

		for(int i=0;i<G[cur].size();i++){
			int v=G[cur][i];
			//cout<<v<<' '<<cur<<endl;
			if(parent[v]==-1 && capacity[cur][v]){
				parent[v]=cur;
				
				flow=min(flow,capacity[cur][v]);
				if(v==t){
					return flow;
				}
				Q.push({v,flow});
			}
		}
	}
	return 0;
}

int maxflow(int s,int t)
{
	int flow=0;
	vector<int>parent(105);

	int new_flow;

	while(new_flow=bfs(s,t,parent)){
		flow+=new_flow;
		int cur=t;
		while(cur!=s){
			int pre=parent[cur];
			capacity[pre][cur]-=new_flow;
			capacity[cur][pre]+=new_flow;
			cur=pre;
		}
	}
	return flow;
}



int main()
{
	int w,t;
	cin>>t;
	while(t--){
		for(int i=0;i<sz;i++){
			G[i].clear();
		}
		memset(capacity,0,sizeof capacity);
		cin>>n>>m;
		string s1,s2;
		w=m+1;
		map<string,int>id;
		id.clear();
		for(int i=1;i<=m;i++){
			cin>>s1>>s2;
			if(id.find(s1)==id.end()){
				id[s1]=w++;
			}
			if(id.find(s2)==id.end()){
				id[s2]=w++;
			}
			G[0].push_back(i);
			G[i].push_back(0);

			G[i].push_back(id[s1]);
			G[id[s1]].push_back(i);

			G[i].push_back(id[s2]);
			G[id[s2]].push_back(i);

			capacity[i][id[s1]]=1;
			capacity[i][id[s2]]=1;
			capacity[0][i]=1;
		}
		for(int i=m+1;i<w;i++){
			G[i].push_back(w);
			G[w].push_back(i);
			capacity[i][w]=(n/6);
		}
		int flw=maxflow(0,w);
		//cout<<flw<<endl;
		if(flw==m){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}


}
