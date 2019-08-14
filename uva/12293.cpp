#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool win(int a,int b)
{
    if(a==b) return 0;

    if(a>b) swap(a,b);


    for(int i=1;i<=b-i;i++){
        if(win(i,b-i)==0) return 1;
    }
    return 0;
}


int main()
{

    int n;

    while(scanf("%d",&n) && n)
    {
        bool flag=1;
        while(n){
            if(n%2==0){
                flag=0;
                break;
            }
            n/=2;
        }
        if(!flag){
            printf("Alice\n");
        }else{
            printf("Bob\n");
        }
    }


}
