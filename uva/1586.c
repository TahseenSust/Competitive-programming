#include<stdio.h>
#include<string.h>
int main()
{
    char ch[80];
    int i,T;
    scanf("%d",&T);
    while(T--){
        double mass=0,nm,t_m,j=0;
        i=0;
        scanf("%s",ch);
        if(ch[0]>=48&&ch[0]<=57){
        while(ch[i]>=48&&ch[i]<=57){
                j=(j*10)+(double)(ch[i]-48);
                i++;
            }
        }else{
            j=1;
        }
        for(;i<strlen(ch);i++){
            t_m=0,nm=0;
            if(ch[i]=='C'||ch[i]=='H'||ch[i]=='O'||ch[i]=='N'){
                if(ch[i]=='C'){
                    t_m=12.01;
                }else if(ch[i]=='O'){
                    t_m=16.00;
                }else if(ch[i]=='H'){
                    t_m=1.008;
                }else if(ch[i]=='N'){
                    t_m=14.010;
                }
                i++;
                if(ch[i]>=48&&ch[i]<=57){
                    while(ch[i]>=48&&ch[i]<=57){
                        nm=(nm*10)+(double)(ch[i]-48);
                        i++;
                    }
                }else{
                    nm=1;
                }
                i--;
            }
            mass=(t_m*nm)+mass;
        }
        printf("%.3lf\n",mass*j);
    }
    return 0;
}
