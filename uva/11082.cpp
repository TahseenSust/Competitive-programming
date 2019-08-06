#include "bits/stdc++.h"
using namespace std;

const int sz=105;
const int oo=1<<30;

struct FlowEdge {
    int u, v;
    long long cap, flow = 0;
    FlowEdge(int u, int v, long long cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    map<pair<int,int>,int>mp;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(sz);
        level.resize(sz);
        ptr.resize(sz);
    }

    void add_edge(int u, int v, long long cap) {
        edges.push_back(FlowEdge(u, v, cap));
        edges.push_back(FlowEdge(v, u, 0));
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        mp[{u,v}]=m;
        mp[{v,u}]=m+1;
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].v] != -1)
                    continue;
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int u, long long pushed) {
        if (pushed == 0)
            return 0;
        if (u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
    long long flow_gese(int u,int v)
    {
    	int id=mp[{u,v}];
    	return edges[id].flow;
    }
};

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		if(tc-1){
			cout<<endl;
		}
		int r,c,sum1[22]={0},sum2[22]={0};

		cin>>r>>c;

		Dinic flow(50,0,51);

		for(int i=1;i<=r;i++){
			cin>>sum1[i];
			//cout<<sum1[i]-sum1[i-1]<<' ';
			flow.add_edge(0,i*2,sum1[i]-sum1[i-1]-c);
		}
		for(int i=1;i<=c;i++){
			cin>>sum2[i];
			//cout<<sum2[i]-sum2[i-1]<<' ';
			flow.add_edge(i*2+1,51,sum2[i]-sum2[i-1]-r);
		}

		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				flow.add_edge(i*2,j*2+1,19);
			}
		}

		int ans=flow.flow();
		printf("Matrix %d\n",tc);
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cout<<1+flow.flow_gese(2*i,2*j+1)<<' ';
			}
			cout<<endl;
		}
	}
}
