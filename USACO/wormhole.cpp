/*
ID: tahseen1
PROG: wormhole
LANG: C++
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf
int N,X[20],Y[20];
int parter[20];
int Next[20];

bool cycle()
{
    for(int i=1;i<=N;i++){
        int pos=i;
        for(int j=0;j<N;j++){
            pos= Next[parter[pos]];
        }
        if(pos!=0) return true;
    }
    return false;
}
int solve()
{
    int i,total=0;
    for(i=1;i<=N;i++){
        if(parter[i] == 0)
            break;
    }

    if(i>N){
        if(cycle()) return 1;
        return 0;
    }
    for(int j=i+1;j<=N;j++){
        if(parter[j] == 0){
            parter[i] = j;
            parter[j] = i;
            total += solve();
            parter[i] = parter[j] = 0;
        }
    }
    return total;
}
int main()
{
    //ofstream cout ("wormhole.out");
    //ifstream cin ("wormhole.in");
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>X[i]>>Y[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(X[j]>X[i] && Y[i]==Y[j]){
                if(Next[i]==0 || X[j]-X[i]<X[Next[i]]-X[i]){
                    Next[i]=j;
                }
            }
        }
    }
    cout<<solve()<<endl;
}
