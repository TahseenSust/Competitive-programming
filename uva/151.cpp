#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n && n){
        for(int i=1;i<=n;i++){
            bool f[105];
            memset(f,1,sizeof f);
            int sz=n,p=0;
            while(f[12]){
                f[p]=0;
                if(f[12]==0) break;
                sz--;
                if(sz==1){
                    break;
                }
                int d=i;
                while(d){
                    p+=1;
                    p%=n;
                    d-=f[p];
                }
            }
            if(f[12] && sz==1){
                cout<<i<<endl;
                break;
            }
        }
    }
}
