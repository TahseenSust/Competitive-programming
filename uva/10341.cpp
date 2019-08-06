#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-7
double p,q,r,s,t,u;

double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bisection()
{
    double l=0,h=1;
    while(l+EPS<h){
        double x=(l+h)/2;
        if(f(l)*f(x)<=0){
            h=x;
        }else{
            l=x;
        }
    }
    return (l+h)/2;
}
int main()
{
    while(cin>>p>>q>>r>>s>>t>>u){
        if(f(0)*f(1)>0){
            printf("No solution\n");
        }else{
            printf("%.4lf\n",bisection());
        }
    }
}
