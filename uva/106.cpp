#include<bits/stdc++.h>
using namespace std;

const int sz=1000002;
bool vis[sz];
int main()
{
    int n;

    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof vis);
        int ans=0,cnt=0;
        for(int i=1;i<=sqrt(n);i++){
            for(int j=i+1;j<=sqrt(n);j++){
                if(__gcd(i,j)==1){
                    int x=2*i*j;
                    int y=j*j-i*i;
                    int z=i*i+j*j;
                    if(z>n) break;
                    if(__gcd(x,__gcd(y,z))==1){
                        ans++;
                    }
                    while(z<=n){
                        vis[x]=vis[y]=vis[z]=1;
                        x+=2*i*j;
                        y+=j*j-i*i;
                        z+=i*i+j*j;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            cnt+=vis[i];
        }
        printf("%d %d\n",ans,n-cnt);
    }
}
