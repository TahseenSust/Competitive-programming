/*
ID: tahseen1
PROG: crypt1
LANG: C++11
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int n,bool SET[])
{
    while(n){
        if(!SET[n%10]){
            return false;
        }
        n/=10;
    }
    return true;
}
int main()
{
    ofstream cout ("crypt1.out");
    ifstream cin ("crypt1.in");
    int n,x,ans=0;
    cin>>n;
    bool SET[n+5]={0};
    for(int i=0;i<n;i++){
        cin>>x;
        SET[x] = true;
    }
    if(n!=1 && x!=1){
        for(int i=100;i<=999;i++){
            bool ok=false;
            x=i;
            if(SET[x%10] && SET[(x/10)%10] && SET[(x/100)%10]){
                ok=true;
            }
            for(int j=10;j<=99 && ok;j++){
                int p1,p2,p;
                bool f1=0,f2=0,f=0;
                if(SET[j%10] && SET[(j/10)%10]){
                    p1=(i*(j%10));
                    p2=(i*((j/10)%10));
                    p=i*j;
                    f1=check(p1,SET);
                    f2=check(p2,SET);
                    f=check(p,SET);
                    if(f1 && f2 && f && p1<1000 && p2<1000 && p<10000){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
