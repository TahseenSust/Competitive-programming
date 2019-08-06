#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ara[100000];
int multiply(int ara[],int n,int sz)
{
    int carry=0;
    for(int i=0;i<sz;i++){
        int prod=ara[i]*n+carry;
        ara[i]=prod%10;
        carry=prod/=10;
    }
    while(carry){
        ara[sz]=carry%10;
        carry/=10;
        sz++;
    }
    return sz;

}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        ara[0]=1;
        ara[1]=1;
        int sz=1;
        for(int i=2;i<=n;i++){
            sz=multiply(ara,i,sz);
        }
        printf("%d!\n",n);
        for(int i=sz-1;i>=0;i--){
            cout<<ara[i];
        }
        printf("\n");
    }
}

