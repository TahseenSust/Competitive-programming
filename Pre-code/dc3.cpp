const int kinds = 128;///maximum ASCII value of any character of the string
char str[N];
int K, buc[N], r[N], sa[N], X[N], Y[N], high[N];
bool cmp(int *r, int a, int b, int x)
{
	return (r[a] == r[b] && r[a + x] == r[b + x]);
}
void suffix_array_DA(int n, int m)
{
	int *x = X, *y = Y, i, j, k = 0, l;
	memset(buc, 0, sizeof(buc));
	for (i = 0; i < n; i++) buc[ x[i] = str[i] ]++;
	for (i = 1; i < m; i++) buc[i] += buc[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--buc[x[i]]] = i;
	for (l = 1, j = 1; j < n; m = j, l <<= 1)
	{
		j = 0;
		for (i = n - l; i < n; i++) y[j++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= l) y[j++] = sa[i] - l;
		for (i = 0; i < m; i++) buc[i] = 0;
		for (i = 0; i < n; i++) buc[ x[y[i]] ]++;
		for (i = 1; i < m; i++) buc[i] += buc[i - 1];
		for (i = n - 1; i >= 0; i--) sa[ --buc[ x[y[i]] ]] = y[i];
		for (swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], l) ? j - 1 : j++;
	}
	for (i = 1; i < n; i++) r[sa[i]] = i;
	for (i = 0; i < n - 1; high[r[i++]] = k)
		for (k ? k-- : 0, j = sa[r[i] - 1]; str[i + k] == str[j + k]; k++);
}
vector<int> suffix_array_construction(string s)
{
	int n = s.size();
	for (int i = 0; i < n; i++) str[i] = s[i];
	str[n] = '\0';
	suffix_array_DA(n + 1, kinds);
	vector<int>saa;
	for (int i = 1; i <= n; i++) saa.eb(sa[i]);
	return saa;
}
vector<int> lcp_construction(string const& s, vector<int> const& p)
{
	int n = s.size();
	vector<int> rank(n, 0);
	for (int i = 0; i < n; i++) rank[p[i]] = i;
	int k = 0;
	vector<int> lcp(n - 1, 0);
	for (int i = 0; i < n; i++) {
		if (rank[i] == n - 1) {
			k = 0;
			continue;
		}
		int j = p[rank[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
		lcp[rank[i]] = k;
		if (k) k--;
	}
	return lcp;
}
const int MX = 18;
int st[N][MX];
int lg[N];
void pre()
{
	lg[1] = 0;
	for (int i = 2; i < N; i++)
		lg[i] = lg[i / 2] + 1;
}
void build(vector<int> &lcp)
{
	int n = lcp.size();
	for (int i = 0; i < n; i++)
		st[i][0] = lcp[i];
	for (int k = 1; k < MX; k++)
		for (int i = 0; i < n; i++)
		{
			st[i][k] = st[i][k - 1];
			int nxt = i + (1 << (k - 1));
			if (nxt >= n) continue;
			st[i][k] = min(st[i][k], st[nxt][k - 1]);
		}
}
///minimum of lcp[l.......r]
int get(int l, int r)
{
	int k = lg[r - l + 1];
	return min(st[l][k], st[r - (1 << k) + 1][k]);
}
int ra[N], sz;
///lcp of suffix starting from i and j
int lcp_(int i, int j)
{
	if (i == j) return sz - i;
	int l = ra[i];
	int r = ra[j];
	if (l > r) swap(l, r);
	return get(l, r - 1);
}
string ss;
///lower bound of string t
int lb(string &t, vi &sa) {
	int l = 0, r = sz - 1;
	int k = t.size();
	int ans = sz;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ss.substr(sa[mid], min(sz - sa[mid], k)) >= t) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
///upper bound of string t
int ub(string &t, vi &sa) {
	int l = 0, r = sz - 1;
	int k = t.size();
	int ans = sz;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ss.substr(sa[mid], min(sz - sa[mid], k)) > t) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
int main()
{
	fast;
	int i, j, k, n, m, q;
	string s;
	cin >> s;
	n = s.size();
	vector<int> sa = suffix_array_construction(s);
	vector<int> lcp = lcp_construction(s, sa);
	sz = n;
	ss = s;
	for (i = 0; i < n; i++) ra[sa[i]] = i;
	pre();
	build(lcp);
	for (i = 0; i < n; i++) cout << sa[i] << ' ';
	cout << nl;
	for (i = 0; i < n - 1; i++) cout << lcp[i] << ' ';
	cout << nl;
	cin >> q;
	///lcp of suffixes
	while (q--) {
		cin >> i >> j;
		cout << lcp_(i, j) << nl;
	}
	cin >> q;
	///number of occurrences of a pattern, not in sorted order
	while (q--) {
		string t;
		cin >> t;
		int l = lb(t, sa);
		int r = ub(t, sa);
		debug(l, r);
		for (i = l; i < r; i++) cout << sa[i] << ' ';
		cout << nl;
	}
	return 0;
}
