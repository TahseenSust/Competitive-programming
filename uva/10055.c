#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
            if(n<=m)
                printf("%d\n",m-n);
            else if(n>=m)
                printf("%d\n",n-m);

    }
    return 0;
}
