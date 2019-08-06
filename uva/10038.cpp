#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int num[3500];
    int dif[3500];
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        for(int i=0;i<n-1;i++){
            dif[i]=abs(num[i]-num[i+1]);
        }
        int jolly=true;
        sort(dif,dif+(n-1));
        for(int i=0;i<n-1;i++){
            if(dif[i]!=i+1){
                jolly=false;
                break;
            }
        }
        if(jolly){
            printf("Jolly\n");
        }else{
            printf("Not jolly\n");
        }
    }
}
