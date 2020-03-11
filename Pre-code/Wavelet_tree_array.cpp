#include <bits/stdc++.h>
using namespace std;
// S=sorted list
// tree=wavelet tree
// L=বামে এখন পর্যন্ত কয়টা গেছে
// ls বামের যোগফল 
// SL=Sum left
const int mx=100005;
int arr[mx],n;
const int sqr=20;
int s[mx],tree[sqr][mx],L[sqr][mx];
long long ls[sqr][mx],SL;
void build(int l, int r, int d)
{
	if (l == r)return;
	int mid = (l + r) >> 1, cnt = 0, lc = l, rc = mid + 1, ec = 0;
	for (int i = l; i <= r; i++) if (tree[d][i] < s[mid])cnt++;
	for (int i = l; i <= r; i++)
	{
		if ((tree[d][i] < s[mid]) || (tree[d][i] == s[mid] && ec < (mid - l + 1 - cnt)))
		{
			tree[d + 1][lc++] = tree[d][i];
			ls[d][i] = ls[d][i - 1] + tree[d][i];
			if (tree[d][i] == s[mid])ec++;
		}
		else
		{
			tree[d + 1][rc++] = tree[d][i];
			ls[d][i] = ls[d][i - 1];
		}
		L[d][i] = L[d][l - 1] + lc - l; //বামে এখন পর্যন্ত কয়টা গেছে
	}
	build(l, mid, d + 1);
	build(mid + 1, r, d + 1);
}
void init(int *arr, int n)
{
	for (int i = 1; i <= n; i++)
	{
		tree[0][i] = arr[i];
		s[i] = tree[0][i];
	}
	sort(s + 1, s + n + 1);
	build(1, n, 0);
}
//kth smallest element in [x, y]
int kth(int l, int r, int d, int x, int y, int k)
{	//1,n,0,x,y,k
	if (l == r) {
		SL += tree[d][l];
		return tree[d][l];
	}
	int cnt = L[d][y] - L[d][x - 1];
	int mid = (l + r) >> 1;
	if (cnt >= k)
	{
		int newx = L[d][x - 1] - L[d][l - 1];
		int newy = L[d][y] - L[d][l - 1];
		return kth(l, mid, d + 1, l + newx, l + newy - 1, k);
	}
	else
	{
		int newx = x - l - (L[d][x - 1] - L[d][l - 1]);
		int newy = y - l + 1 - (L[d][y] - L[d][l - 1]);
		SL += ls[d][y] - ls[d][x - 1];
		return kth(mid + 1, r, d + 1, mid + 1 + newx, mid + newy, k - cnt);
	}
}
//count of nos in [l, r] Less than or equal to k
int LTE(int l, int r, int d, int x, int y, int k)
{	//1,n,0,x,y,k
	if (l == r) {
		if(l>y || l<x)return 0;
		SL += tree[d][l] * (tree[d][l] <= k);
		return tree[d][l] <= k;
	}
	int cnt = L[d][y] - L[d][x - 1], mid = (l + r) >> 1;
	if (s[mid] <= k)
	{
		int newx = x - l - (L[d][x - 1] - L[d][l - 1]);
		int newy = y - l + 1 - (L[d][y] - L[d][l - 1]);
		SL += ls[d][y] - ls[d][x - 1];
		return cnt + LTE(mid + 1, r, d + 1, mid + 1 + newx, mid + newy, k);
	}
	else
	{
		int newx = L[d][x - 1] - L[d][l - 1];
		int newy = L[d][y] - L[d][l - 1];
		return LTE(l, mid, d + 1, l + newx, l + newy - 1, k);
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	init(arr,n);
	// cout<<kth(1,n,0,4,6,3);cout<<' '<<SL<<endl;
	cout<<LTE(1,n,0,4,6,3)<<' ';cout<<SL<<endl;
	return 0;
}
