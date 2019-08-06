/*
5
dave laura owen vick amr
dave 200 3 laura owen vick
owen 500 1 dave
amr 150 2 vick owen
laura 0 2 amr vick
vick 0 0
3
liz stiv dav
liz 30 1 stiv
stiv 55 2 liz dav
dav 0 2 stiv liz

*/

#include<stdio.h>
#include<string.h>
int main()
{
    char nam[50][50];
    char nam1[50];
    char nam2[50];
    int n,cnt=0;
    while(scanf("%d",&n)==1){
        int sp=0,rec=0,ex=0,i=0,j=0,k=0,p=0;
        cnt++;
        if(cnt>1)
            printf("\n");
        int total[50]={0};
        for(i=0;i<n;i++){
            scanf("%s%*c",nam[i]);
        }
        for(i=0;i<n;i++){
            ex=0,rec=0;
            scanf("%s",nam1);
            scanf("%d",&sp);
            scanf("%d",&p);

            if(sp!=0&&p!=0){
                ex=sp%p;
                rec=sp/p;
            }
            if(p==0)
                ex=sp;

            for(k=0;k<p;k++){
                scanf("%s%*c",nam2);
                for(j=0;j<n;j++){
                    if(strcmp(nam2,nam[j])==0){
                        total[j]=total[j]+rec;
                    }
                }
            }
            //gift taker
            for(j=0;j<n;j++){
                if(strcmp(nam1,nam[j])==0){
                    total[j]=total[j]-sp+ex;
                }
            }

        }
        for(i=0;i<n;i++){
            printf("%s %d\n",nam[i],total[i]);
        }

    }
    return 0;
}
