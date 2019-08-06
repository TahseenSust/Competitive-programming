#include<stdio.h>
int main()
{
    int n[50];
    int i,j;
    int m;
    while(scanf("%d",&m)!=EOF){
        int count=0;
        for(i=0;i<m;i++){
            scanf("%d",&n[i]);
        }
        for(i=0;i<m-1;i++){
            for(j=i+1;j<m;j++){
                if(n[i]>n[j]){
                    count++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",count);
    }

    return 0;
}
