#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,a[1100];
    while(cin>>n && n){
        while(cin>>a[0] && a[0]){
            for(int i=1;i<n;i++){
                cin>>a[i];
            }
            stack<int>S;
            bool flag=1;
            bool p[n+5]={0};
            for(int i=0;i<n;i++){
                for(int j=1;j<=a[i];j++){
                    if(!p[j]){
                        S.push(j);
                        p[j]=1;
                    }
                }
                if(S.top()!=a[i]){
                    flag=0;
                }
                S.pop();
            }
            cout<<(flag?"Yes\n":"No\n");
        }
        cout<<'\n';
    }
}
