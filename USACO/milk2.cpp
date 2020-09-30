/*
ID: tahseen1
PROG: milk2
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool t[1000050];
int main()
{
    #ifndef ONLINE_JUDGE
        ofstream cout ("milk2.out");
        ifstream cin ("milk2.in");
    #endif // ONLINE_JUDGE
    int n,s,e,st=INT_MAX,en=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        if(s<st){st=s+1;};
        if(e>en){en=e;};
        for(int j=s+1;j<=e;j++){
            t[j]=1;
        }
    }
    int ans1=0,ans2=0,cnt=0;
    for(int i=st;i<=en;i++){
        cnt=0;
        while(t[i]){
            i++;
            cnt++;
        }
        if(ans1<cnt){
            ans1=cnt;
        }
    }
    for(int i=st;i<=en;i++){
        cnt=0;
        while(!t[i]){
            i++;
            cnt++;
        }
        if(ans2<cnt){
            ans2=cnt;
        }
    }
    cout<<ans1<<' '<<ans2<<endl;
}
