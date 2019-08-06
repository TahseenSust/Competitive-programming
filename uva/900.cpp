#include<bits/stdc++.h>
using namespace std;
long long arr[100];
void memory()
{
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<100;i++){
        arr[i]=-1;
    }
}
long long fib(int n)
{
    if(n==1)
        return arr[1];
    if(n==0)
        return arr[0];
    if(arr[n]==-1)
        arr[n]=fib(n-1)+fib(n-2);
    return arr[n];
}
int main()
{
    memory();
    long long wall;
    while(scanf("%lld",&wall)&&wall!=0){
        printf("%lld\n",fib(wall));
    }
}
