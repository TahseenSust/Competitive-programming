#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    int i=0;
    double x1[50],y1[50],x2[50],y2[50]={0};
    double x,y;
    char rec[50];
    while(1){
        scanf("%c",&rec[i]);
        if(rec[i]=='*') break;
        else if(rec[i]=='r') scanf("%lf %lf %lf %lf ",&x1[i],&y1[i],&x2[i],&y2[i]);
        else if(rec[i]=='c'){
            scanf("%lf %lf %lf ",&x1[i],&y1[i],&x2[i]);
            y2[i]=9999.9;
        }
        i++;
    }
    int point=1;
    bool faisi=true;
    while(1){
        scanf("%lf %lf",&x,&y);
        if(x==9999.9&&y==9999.9) break;
        for(int n=0;n<i;n++){
            if(y2[n]==9999.9){
                if(((x-x1[n])*(x-x1[n])+(y-y1[n])*(y-y1[n]))<x2[n]*x2[n]){
                    printf("Point %d is contained in figure %d\n",point,n+1);
                    faisi=false;
                }
            }else{
                if(x>x1[n]&&x<x2[n]&&y<y1[n]&&y>y2[n]){
                    printf("Point %d is contained in figure %d\n",point,n+1);
                    faisi=false;
                }
            }
        }
        if(faisi){
            printf("Point %d is not contained in any figure\n",point);
        }
        point++;
        faisi=true;
    }
}
/*
r 8.5 17.0 25.5 -8.5 (8.5 -8.5 25.5 17.0)
r 0.0 0.0 5.5 10.3   (0.0 10.3 5.5 0.0)
r 2.5 2.5 12.5 12.5
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9
*/
