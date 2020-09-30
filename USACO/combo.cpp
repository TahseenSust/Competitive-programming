
/*
ID: tahseen1
PROG: combo
LANG: C++
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf

bool combo[100][100][100];
int main()
{
    //ofstream cout ("combo.out");
    //ifstream cin ("combo.in");
    //freopen("out.txt","w",stdout);
    int n,a,b,c,x,y,z,p,q,r;
	cin>>n>>a>>b>>c>>x>>y>>z;
	p=(a-2+n)%n;
	q=(b-2+n)%n;
	r=(c-2+n)%n;
	int cnt=0;
	for(int i=p;i<=p+4 && i%n<=n;i++){
        for(int j=q;j<=q+4 && j%n<=n;j++){
            for(int k=r;k<=r+4 && k%n<=n;k++){
                //cout<<i%n<<' '<<j%n<<' '<<k%n<<'\n';
                if(!combo[i%n][j%n][k%n]){
                    combo[i%n][j%n][k%n]=1;
                    cnt++;
                }
            }
        }
	}
	p=(x-2+n)%n;
	q=(y-2+n)%n;
	r=(z-2+n)%n;
	for(int i=p;i<=p+4 && i%n<=n;i++){
        for(int j=q;j<=q+4 && j%n<=n;j++){
            for(int k=r;k<=r+4 && k%n<=n;k++){
                if(!combo[i%n][j%n][k%n]){
                    //cout<<i%n<<' '<<j%n<<' '<<k%n<<'\n';
                    combo[i%n][j%n][k%n]=1;
                    cnt++;
                }
            }
        }
	}
	cout<<cnt<<endl;
}
