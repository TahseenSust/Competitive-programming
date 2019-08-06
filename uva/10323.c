#include<stdio.h>
long long fact(long long n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
long long abs(long long n)
{
    if(n<0) return n*(-1);
    else return n;
}
int main()
{
    long long n,a;
    while(scanf("%lld",&a)!=EOF){
        if(a<8){
            if(a<0){
                abs(a);
                if(a&1){
                    printf("Overflow!\n");
                }else{
                    printf("Underflow!\n");
                }
            }else
                printf("Underflow!\n");

        }
        else if(a>13)
            printf("Overflow!\n");
        else{
            n=fact(a);
            printf("%lld\n",n);
        }
    }
    return 0;
}

