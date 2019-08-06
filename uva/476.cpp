#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    int i=0;
    double x1[50],y1[50],x2[50],y2[50];
    double x,y;
    char rec;
    while(1){
        scanf("%c",&rec);
        if(rec=='*') break;
        scanf("%lf%lf",&x1[i],&y1[i]);
        scanf("%lf%lf ",&x2[i],&y2[i]);
        i++;
    }
    int point=1;
    bool faisi=true;
    while(1){
        scanf("%lf %lf",&x,&y);
        if(x==9999.9&&y==9999.9) break;
        for(int n=0;n<i;n++){
            //printf("\n--------%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf \n\n",x,x1[n],x,x2[n],y,y1[n],y,y2[n]);
            if(x>x1[n]&&x<x2[n]&&y>y1[n]&&y<y2[n]){
                //printf("\n%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf \n\n",x,x1[n],y,y1[n],x2[n],y2[n]);
                printf("Point %d is contained in figure %d\n",point,n+1);
                faisi=false;
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
r 8.5 17.0 25.5 -8.5
r 0.0 0.0 5.5 10.3
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
