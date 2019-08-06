#include<bits/stdc++.h>
using namespace std;
int main()
{
    char year[100000];
    int line=0;
    while(scanf("%s",year)!=EOF){
        if(line)
            printf("\n");
        line=1;
        int leap4=0,leap100=0,leap400=0,hulu=0,bulu=0;
        int len=strlen(year);
        for(int i=0;i<len;i++){
            leap4=(leap4*10+year[i]-48)%4;
            leap100=(leap100*10+year[i]-48)%100;
            leap400=(leap400*10+year[i]-48)%400;
            hulu=(hulu*10+year[i]-48)%15;
            bulu=(bulu*10+year[i]-48)%55;
        }
        if((!leap4&&leap100)||!leap400){
            printf("This is leap year.\n");
            if(!hulu)
                printf("This is huluculu festival year.\n");
            if(!bulu)
                printf("This is bulukulu festival year.\n");
        }
        else
        {
            if(!hulu)
                printf("This is huluculu festival year.\n");
            else{
                printf("This is an ordinary year.\n");
            }
        }
    }
}
