#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum,set=0;
    int hi[100];
    while(scanf("%d",&n)&&n!=0){
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&hi[i]);
            sum=sum+hi[i];
        }
        int lagbo=sum/n,move=0;
        for(int i=0;i<n;i++){
            if(hi[i]>lagbo){
                move=hi[i]-lagbo+move;
            }
        }
        printf("Set #%d\n",++set);
        printf("The minimum number of moves is %d.\n\n",move);
    }
}
