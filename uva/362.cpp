#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    int file_size,data_set=0;
    while(scanf("%d",&file_size)&&file_size!=0){
        int transfer=0,in_s,time=0,t=0;
        int last_5=0;
        printf("Output for data set %d, %d bytes:\n",++data_set,file_size);
        while(1){
            scanf("%d",&in_s);
            transfer=transfer+in_s;
            last_5=last_5+in_s;
            time++;
            if(time%5==0){
                printf("   Time remaining: ");
                if(last_5==0){
                    printf("stalled\n");
                }else{
//                    double in_1=(double)(last_5/5);
//                    last_5=0;
//                    double baki=(double)file_size-transfer;

                   // printf("%d seconds\n",(int)ceil(baki/in_1));
                    printf("%d seconds\n",((file_size-transfer)*5 + last_5 - 1)/last_5);
                    last_5=0;
                }
            }
            if(transfer>=file_size){
                break;
            }
        }
        printf("Total time: %d seconds\n\n",time);
    }
}
