/*
Honesty is the best policy
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX=1000000000000000000ll;

int a[35],b[35],c[35];
struct dt
{
    int a,b,c;
    
};


void all(int i,int x,int y,int z,int limit,vector<dt>&X)
{
    if(i==limit){
        dt tmp={x,y,z};
        X.push_back(tmp);
        return;
    }
    all(i+1,x,y,z,limit,X);
    all(i+1,x+a[i],y+b[i],z+c[i],limit,X);
}



bool cmp(dt a,dt b)
{
    if(a.a==b.a){
        if(a.b==b.b){
            return a.c<b.c;
        }
        return a.b<b.b;
    }
    return a.a<b.a;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        vector<dt>X,Y;

        int x,y,z,n;
        scanf("%d%d%d%d",&x,&y,&z,&n);

        string str;

        for(int i=0;i<n;i++){
            cin>>str;
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }

        all(0,0,0,0,(n/2),X);
        all((n/2),0,0,0,n,Y);

        //cout<<X.size()<<endl;
        //cout<<Y.size()<<endl;

        sort(X.begin(),X.end(),cmp);
        sort(Y.begin(),Y.end(),cmp);


        int yi=Y.size()-1;
        str="IMPOSSIBLE";
        for(int i=0;i<X.size();i++){
            int sum1=x-X[i].a;
            int sum2=y-X[i].b;
            int sum3=z-X[i].c;
            while(yi>=0){
                if(sum1>Y[yi].a){
                    break;
                }else if(sum1==Y[yi].a && sum2==Y[yi].b && sum3==Y[yi].c){
                    str="POSSIBLE";
                    break;
                }else if(sum1==Y[yi].a && sum2>Y[yi].b){
                    break;
                }else if(sum1==Y[yi].a && sum2==Y[yi].b && sum3>Y[yi].c){
                    break;
                }
                yi--;
            }
        }
        cout<<str<<endl;
    }

}

