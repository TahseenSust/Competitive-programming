#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=(1<<28);
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int sz=1505;
int capacity[sz][sz];
vector<int>G[sz];
int k,p;

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
	vector<int>parent(sz);

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
	int d,u,tot;
	while(cin>>k>>p){
		if(!k && !p){
			return 0;
		}
		for(int i=0;i<sz;i++){
			G[i].clear();
		}
		memset(capacity,0,sizeof capacity);
		int cat[22];
		tot=0;
		for(int i=1;i<=k;i++){
			cin>>cat[i];
			tot+=cat[i];
		}
	
		for(int i=1;i<=p;i++){
			cin>>d;
			while(d--){
				cin>>u;
				G[i].push_back(1000+u);
				G[u+1000].push_back(i);
				capacity[i][u+1000]=1;
			}
			G[0].push_back(i);
			G[i].push_back(0);
			capacity[0][i]=1;
		}
	
		for(int i=1;i<=k;i++){
			G[i+1000].push_back(1501);
			G[1501].push_back(i+1000);
			capacity[i+1000][1501]=cat[i];
		}
		int flw=maxflow(0,1501);
	
		if(flw==tot){
			cout<<1<<endl;
			bool mark[1010]={0};
			for(int i=1;i<=k;i++){
				for(int j=1;j<=p;j++){
					if(capacity[j][i+1000]==0 && capacity[i+1000][j]==1 && mark[j]==0){
						mark[j]=1;
						cout<<j<<' ';
					}
				}
				cout<<endl;
			}
		}else{
			cout<<0<<endl;
		}
	}

}
