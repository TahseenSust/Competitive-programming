#include<bits/stdc++.h>
using namespace std;
int main()
{
    int H,M;
    double mx,hour_angle,min_angle;
    while(scanf("%d:%d",&H,&M)){
        if(H==0&&M==0){
            return 0;
        }
        if(M==0){
            min_angle=(double)60*6;
        }else{
            min_angle=(double)M*6;
        }
        hour_angle=(double)(H*60+M)*.5;
        if(hour_angle>min_angle){
            if(hour_angle-min_angle>180){
                mx=(hour_angle-min_angle)-180;
                printf("%.3lf\n",180-mx);
            }else{
                printf("%.3lf\n",hour_angle-min_angle);
            }

        }
        else{
            if(min_angle-hour_angle>180){
                mx=(min_angle-hour_angle)-180;
                printf("%.3lf\n",180-mx);
            }else{
                printf("%.3lf\n",min_angle-hour_angle);
            }
        }
    }
}
