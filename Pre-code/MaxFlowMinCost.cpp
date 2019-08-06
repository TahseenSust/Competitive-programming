#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=(1<<28);
const int MOD=1266523;
const int sz=505;

vector<int>G[sz];
int cost[sz][sz],capacity[sz][sz],n,m;


void shortest_paths(int v0, vector<int>& d, vector<int>& p) {
    d.assign(sz, INF);
    d[v0] = 0;
    vector<int> m(sz, 2);
    deque<int> q;
    q.push_back(v0);
    p.assign(sz, -1);
    while (!q.empty()) {
        int u = q.front();
        //cout<<u<<endl;
        q.pop_front();
        m[u] = 0;
        for (int i=0;i<G[u].size();i++) {
            int v=G[u][i];
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (m[v] == 2) {
                    m[v] = 1;
                    q.push_back(v);
                } else if (m[v] == 0) {
                    m[v] = 1;
                    q.push_front(v);
                }
            }
        }
    }
}

int min_cost_flow(int K, int s, int t) {


    int flow = 0;
    int cost = 0;
    vector<int> d, p;

    while (flow < K) {
        shortest_paths(s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    //cout<<flow<<endl;

    return cost;
}


int main()
{
	


}
