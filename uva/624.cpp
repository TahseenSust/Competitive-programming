#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;


ll cd[25],N,k;
vector<int>path;

ll print(ll i,ll tape)
{

    if(i==k){
        return tape;
    }

    ll p1=0,p2=0;
    if(tape+cd[i]<=N){

        p1=print(i+1,tape+cd[i]);
    }
    p2=print(i+1,tape);
    return max(p1,p2);

}

void backtrack(int i,ll a,ll b,vector<int>p)
{
    if(a==b || i==k){
        if(p.size()>path.size() && a==b){
            path=p;
        }
        return;
    }
    ll p1=0,p2=0;
    p.push_back(i);
    if(cd[i]+a<=b){
        backtrack(i+1,a+cd[i],b,p);
    }
    p.pop_back();
    backtrack(i+1,a,b,p);

}
int main()
{
    while(cin>>N>>k){
        path.clear();
        for(int i=0;i<k;i++){
            cin>>cd[i];
        }
        vector<int>p;
        ll ans=print(0,0);
        backtrack(0,0,ans,p);
        for(int i=0;i<path.size();i++){
            cout<<cd[path[i]]<<' ';
        }
        cout<<"sum:"<<ans<<endl;
    }

}


