#include<stdio.h>
#include<string.h>
int main()
{
    char a[50];
    int i,j;
    int T;
    scanf("%d",&T);
    while(T--){
        int sum=0;
        scanf("%s",a);
        for(i=0;i<strlen(a);i++){
            if(a[i]=='O'){
                int tsum=0;
                j=i;
                while(a[j]=='O'){
                    tsum=tsum+1;
                    j++;
                }
                sum=sum+tsum;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

