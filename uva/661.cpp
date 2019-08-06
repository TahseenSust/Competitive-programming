#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c,c1[25],mx,v,d,cn=1;
    while(cin>>n>>m>>c && (n!=0&&m!=0&&c!=0)){

        bool ck[25]={0},flag=0;

        for(int i=0;i<n;i++){
            cin>>c1[i];
        }
        v=mx=0;
        while(m--){
            cin>>d;
            if(!ck[d-1]){
                ck[d-1]=1;
                v+=c1[d-1];
                mx=max(mx,v);
                if(v>c){
                    flag=1;
                }
            }else{
                ck[d-1]=0;
                v-=c1[d-1];
            }
        }
        printf("Sequence %d\n",cn++);
        if(flag){
            cout<<"Fuse was blown.\n\n";
        }else{
            cout<<"Fuse was not blown.\n";
            printf("Maximal power consumption was %d amperes.\n\n",mx);
        }
    }
}
