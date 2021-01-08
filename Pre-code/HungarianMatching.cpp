#include <bits/stdc++.h>
using namespace std;

const int N=1000;
/// Complexity: O(n^3) but optimized
/// It finds minimum cost maximal matching.
/// For finding maximum cost maximal matching
/// add -cost and return -matching()
///1-indexed
struct HungarianMatching {
	long long c[N][N], fx[N], fy[N], d[N];
	int mx[N], my[N], arg[N], trace[N];
	queue<int> q;
	int start, finish, n;
	const long long inf = 1e18;
	HungarianMatching() {}
	HungarianMatching(int n): n(n) {
		for (int i = 1; i <= n; ++i) {
			fy[i] = mx[i] = my[i] = 0;
			for (int j = 1; j <= n; ++j) c[i][j] = inf;
		}
	}
	void addedge(int u, int v, long long cost) {
		c[u][v] = min(c[u][v], cost);
	}
	inline long long getC(int u, int v) {
		return c[u][v] - fx[u] - fy[v];
	}
	void initBFS() {
		while (!q.empty()) q.pop();
		q.push(start);
		for (int i = 0; i <= n; ++i) trace[i] = 0;
		for (int v = 1; v <= n; ++v) {
			d[v] = getC(start, v);
			arg[v] = start;
		}
		finish = 0;
	}
	void findAugPath() {
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v = 1; v <= n; ++v) if (!trace[v]) {
					long long w = getC(u, v);
					if (!w) {
						trace[v] = u;
						if (!my[v]) {
							finish = v;
							return;
						}
						q.push(my[v]);
					}
					if (d[v] > w) {
						d[v] = w;
						arg[v] = u;
					}
				}
		}
	}
	void subX_addY() {
		long long delta = inf;
		for (int v = 1; v <= n; ++v) if (trace[v] == 0 && d[v] < delta) {
				delta = d[v];
			}
// Rotate
		fx[start] += delta;
		for (int v = 1; v <= n; ++v) if (trace[v]) {
				int u = my[v];
				fy[v] -= delta;
				fx[u] += delta;
			} else d[v] -= delta;
		for (int v = 1; v <= n; ++v) if (!trace[v] && !d[v]) {
				trace[v] = arg[v];
				if (!my[v]) {
					finish = v; return;
				}
				q.push(my[v]);
			}
	}
	void Enlarge() {
		do {
			int u = trace[finish];
			int nxt = mx[u];
			mx[u] = finish;
			my[finish] = u;
			finish = nxt;
		} while (finish);
	}
	long long matching() {
		for (int u = 1; u <= n; ++u) {
			fx[u] = c[u][1];
			for (int v = 1; v <= n; ++v) {
				fx[u] = min(fx[u], c[u][v]);
			}
		}
		for (int v = 1; v <= n; ++v) {
			fy[v] = c[1][v] - fx[1];
			for (int u = 1; u <= n; ++u) {
				fy[v] = min(fy[v], c[u][v] - fx[u]);
			}
		}
		for (int u = 1; u <= n; ++u) {
			start = u;
			initBFS();
			while (!finish) {
				findAugPath();
				if (!finish) subX_addY();
			}
			Enlarge();
		}
		long long ans = 0;
		for (int i = 1; i <= n; ++i) if (c[i][mx[i]] != inf) ans += c[i][mx[i]];
		return ans;
	}
};
int a[N], b[N], t[N];
int main()
{
	int i, j, k, n, m, u, v, w, cost;
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i] >> b[i] >> t[i];
	HungarianMatching M(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) M.addedge(i + 1, j + 1, -max(0LL, 1LL * a[j] -
			                                  1LL * min(i, t[j])*b[j]));
	}
	cout << -M.matching();
	return 0;
}