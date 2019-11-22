#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m;

    while(scanf("%d%d",&n,&m)!=EOF){
        vector<int>v;
        if(m>1 && n>1){
            while(n!=1){
                if(n%m==0){
                    v.push_back(n);
                }else{
                    break;
                }
                n/=m;
            }
            if(n!=1){
                printf("Boring!\n");
            }else{
                for(auto x:v){
                    printf("%d ",x);
                }
                printf("1\n");
            }
        }else{
            printf("Boring!\n");
        }

    }
}

