#include<bits/stdc++.h>
using namespace std;
vector<int> divi[11000];
void d(int n,int m)
{
    int k=0;
    for(int i=n;i<=m;i++){
        divi[k].resize(0);
        int limit=sqrt(i);
        for(int j=1;j<=limit;j++){
            if(i%j==0){
                divi[k].push_back(j);
                if(j!=i/j)
                    divi[k].push_back(i/j);
            }
        }
        k++;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        long long n,l,u,mx=0,ans=0;
        scanf("%lld %lld",&l,&u);
        d(l,u);
        for(int i=0;i<=u-l;i++){
            if(divi[i].size()>mx){
                mx=divi[i].size();
                ans=l+i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,ans,mx);
    }
}
