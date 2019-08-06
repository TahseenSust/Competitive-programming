#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;


ll cd[25],N,k;

void backtrack(int i,ll a,vector<int>p)
{
    if(a==6){
        cout<<cd[p[0]];
        for(int i=1;i<p.size();i++){
            cout<<' '<<cd[p[i]];
        }
        cout<<endl;
        return;
    }
    if(i==k){
        return;
    }
    p.push_back(i);
    backtrack(i+1,a+1,p);
    p.pop_back();
    backtrack(i+1,a,p);

}
int main()
{
    bool flag=0;
    while(cin>>k && k){
        if(flag){
            cout<<endl;
        }
        flag=1;
        for(int i=0;i<k;i++){
            cin>>cd[i];
        }
        vector<int>p;
        backtrack(0,0,p);
    }

}


