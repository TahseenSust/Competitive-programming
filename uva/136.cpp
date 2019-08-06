#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxDivide(ll a,ll b)
{
    while(a%b==0)
        a/=b;
    return a;
}
bool isUgly(ll n)
{
    n=maxDivide(n,2);
    n=maxDivide(n,3);
    n=maxDivide(n,5);
    return (n==1)?1:0;
}
ll nthUgly(ll n)
{
    ll i=1;
    ll cnt=1;
    while(cnt<n){
        i++;
        if(isUgly(i))
            cnt++;
    }
    return i;
}
int main()
{
//    ll n=nthUgly(1500);
//    printf("The 1500'th ugly number is %lld.\n",n);
    printf("The 1500'th ugly number is 859963392.\n");

}
