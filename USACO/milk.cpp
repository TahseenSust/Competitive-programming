/*
ID: tahseen1
PROG: milk
LANG: C++
*/

/**
--------- -    |   |  /--  ----- ----- |\   |
    |    / \   |___| /__   |___  |___  | \  |
    |   /---\  |   |    /  |     |     |  \ |
    |  /     \ |   | __/   |____ |____ |   \|
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf
bool isvowel(char n)
{
    if(n=='a'||n=='e'||n=='i'||n=='o'||n=='u') return true;
    return false;
}
int fast_power(int n,int p)
{
    if(p==0) return 1;
    if(p==1) return n;
    if(p&1){
        return n*fast_power(n,p-1);
    }else{
        int re=fast_power(n,p/2);
        return re*re;
    }
}
int lcm(int a,int b)
{
	return (a/__gcd(a,b))*b;
}

bool cmp(pair<int,int>a , pair<int,int>b ){
    if(a.first == b.first){
        return a.second>b.second;
    }else{
        return a.first<b.first;
    }
}

int main()
{
    ofstream cout ("milk.out");
    ifstream cin ("milk.in");
    int N,M;
    cin>>N>>M;

    pair<int,int>val[M];
    for(int i=0;i<M;i++){
        cin>>val[i].first>>val[i].second;
    }
    sort(val,val+M,cmp);
    int ans=0,i=0;
    while(N>0){
        if(val[i].second<N){
            ans+=val[i].second*val[i].first;
            N-=val[i].second;
        }else{
            ans+=N*val[i].first;
            N-=val[i].second;
        }
        i++;
    }
    cout<<ans<<endl;
}

