#include <bits/stdc++.h>
using namespace std;
const int oo=(1<<28);
int cost,coin[10];
int value[]={5,10,20,50,100,200};

int dp1[7][50000];
int dp2[7][50000];


int solve2(int i,int w)
{
    if(i==6){
        if(w!=0){
            return oo;
        }
        return 0;
    }

    int &re=dp2[i][w];

    if(re!=-1){
        return re;
    }

    re=oo;

    if(w-value[i]>=0){
        re=1+solve2(i,w-value[i]);
    }
    re=min(re,solve2(i+1,w));

    return re;
}




int solve(int i,int w)
{
    if(i==6){
        if(w==cost){
            return 0;
        }else if(w<cost){
            return oo;
        }else{
            int re=solve2(0,w-cost);
            return solve2(0,w-cost);
        }

    }

    int &re=dp1[i][w];

    if(re!=-1){
        return re;
    }

    re=oo;

    for(int take=0;take<=coin[i];take++){
        re=min(re,take+solve(i+1,w+value[i]*take));
    }

    return re;
}


int main() {
    

    memset(dp2,-1,sizeof dp2);
    while(1){

        bool flag=1;

        for(int i=0;i<6;i++){
            cin>>coin[i];
            if(coin[i]>0) flag=0;
        }

        if(flag) return 0;

        double d;

        cin>>d;

        cost=(d+0.000000001)*100.00;

        memset(dp1,-1,sizeof dp1);

        printf("%3d\n",solve(0,0));
    }
}
