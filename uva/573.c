/*
input:
2 2 2 20
8 6 5 30
97 56 3 10
56 3 1 5
85 26 19 10
59 17 13 11
97 73 23 17
0 0 0 0

output:
failure on day 2
failure on day 3
success on day 2
failure on day 32
failure on day 7
failure on day 6
success on day 2
*/

#include<stdio.h>
int main()
{
    //freopen("input.txt","r",stdin);
    double h,d,u,f,clmb;
    double min;
    int i;
    while(scanf("%lf%lf%lf%lf",&h,&d,&u,&f)){
        if(h==0)
            break;
        min=(d*(f/100));
        i=0;
        clmb=0;
        while(1){
                clmb=clmb+d;
                i++;
                //printf("%d \n",i);
            if(clmb>h||clmb<0){
                break;
            }else{
                clmb=clmb-u;
                if(clmb<0)
                    break;
            }
            d=d-min;
            if(d<0){
                d=0;
            }
           // printf("%.2lf %.2lf\n\n",d,clmb);

        }
        //printf("%.2lf\n",clmb);
        if(clmb<0){
            printf("failure on day %d\n",i);
        }else{
            printf("success on day %d\n",i);
        }
    }
    return 0;
}
