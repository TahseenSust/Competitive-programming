#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int h,k,T,flag=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&h,&k);
        for(int q=1;q<=k;q++){
            if(flag) cout<<endl;
            flag=1;
            for(int i=1;i<=h;i++){
                for(int j=1;j<=i;j++){
                    printf("%d",i);
                }
                printf("\n");
            }
            for(int i=h-1;i>0;i--){
                for(int j=i;j>0;j--){
                    printf("%d",i);
                }
                printf("\n");
            }
        }
    }
}
