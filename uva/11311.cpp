#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    int t,n,m,r,c,ufre,nise,daine,bame;


    scanf("%d",&t);

    while(t--){
        scanf("%d%d%d%d",&n,&m,&r,&c);

        bame=c;
        daine=m-c-1;
        ufre=r;
        nise=n-r-1;

        if(ufre^nise^daine^bame)
        {
            printf("Gretel\n");
        }else
        {
            printf("Hansel\n");
        }

    }

}
