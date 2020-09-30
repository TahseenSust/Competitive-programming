/*
ID: tahseen1
PROG: barn1
LANG: C++
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
int power(int n,int p)
{
	if(p==0) return 1;
	if(p==1) return n;
	if(p&1){
		return n*(n,p-1);
	}
	int re=power(n,p/2);
	return re*re;
}
int lcm(int a,int b)
{
	return (a/__gcd(a,b))*b;
}
int main()
{
    ofstream cout ("barn1.out");
    ifstream cin ("barn1.in");
	int m,s,c;
	int stall[205];
	cin>>m>>s>>c;
	for(int i=0;i<c;i++){
        cin>>stall[i];
	}
	bool S[205]={0};
	sort(stall,stall+c);
	int ans=stall[c-1]-stall[0]+1;
	pair<pair<int,int>,int>P;
	for(int i=0;i<m-1;i++){
        P.second=0;
        for(int j=1;j<c;j++){
            int M=stall[j]-stall[j-1]-1;
            //cout<<M<<endl;
            if(M>P.second && (!S[j-1] || !S[j])){
                P.first.first=j-1;
                P.first.second=j;
                P.second=M;
            }
        }
        ans-=P.second;
        S[P.first.first]=1;
        S[P.first.second]=1;
	}
	//cout<<stall[0]<<' '<<stall[c-1]<<endl;

	if(c<m){
        ans=c;
	}
	cout<<ans<<endl;
}
