/*
(b/1)%10;
(b/10)%10;
(b/100)%10;
*/
//BEGUN SOURCE CODE
#include<stdio.h>
int main()
{
    long long sum,num1,num2,i,count,c,t;
    while(scanf("%lld%lld",&num1,&num2)){
        if(num1==0&&num2==0)
            break;
        sum=num1+num2;
        count=0,t=0;
        for(i=1;;i*=10){
            c=((num1/i)%10)+((num2/i)%10)+t;
            if(c>9){
                count++;
                t=(int)(c/10);
            }else{
                t=0;
            }
            sum=sum-(c*i);
            if(sum<=0)
                break;
        }
        if(count==0)
            printf("No carry operation.\n");
        else if(count==1)
            printf("%lld carry operation.\n",count);
        else
            printf("%lld carry operations.\n",count);
    }
    return 0;
}
//END SOURCE CODE
