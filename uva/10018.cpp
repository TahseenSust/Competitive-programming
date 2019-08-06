#include<bits/stdc++.h>
using namespace std;
bool palinedrome(long long a)
{
    long long rev=0,cnt=0;
    for(long long i=1;i<=a;i=i*10){
        rev=rev*10+((a/i)%10);
        cnt++;
    }
    long long ck=0;
    for(long long i=1;i<=a;i=i*10){
        if(((rev/i)%10)==((a/i)%10)){
            ck++;
        }else{
            break;
        }
    }
    if(ck==cnt){
        return true;
    }else{
        return false;
    }
}
int main()
{
    long long num1,num2=0,count,T;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&num1);
        count=0;
        while(1){
            num2=0;
            for(long long i=1;i<=num1;i=i*10){
                num2=num2*10+((num1/i)%10);
            }
            num1=num1+num2;
            count++;
            if(palinedrome(num1)==true){
                break;
            }

        }
        printf("%lld %lld\n",count,num1);
    }
}
