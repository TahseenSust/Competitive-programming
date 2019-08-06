#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long arr[100][100];
    long long i,j;
    long long x,y;
    while(scanf("%lld%lld",&y,&x)&&(y!=0&&x!=0)){
        if(x>y){
            int temp;
            temp=x;
            x=y;
            y=temp;
        }
        i=0;
        while(i<y){
            arr[0][i]=i+1;
            i++;
        }
        for(i=1;i<x;i++){
            for(j=0;j<y;j++){
            if(j<i)
                arr[i][j]=0;
            else
                arr[i][j]=arr[i-1][j-1]+arr[i][j-1];
            }
        }
        printf("%lld things taken %lld at a time is %lld exactly.\n",y,x,arr[x-1][y-1]);
    }
    return 0;
}
