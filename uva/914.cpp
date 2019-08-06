#include<bits/stdc++.h>
using namespace std;
const int N=1000050;
bitset<N> ck;
void seive()
{
    ck.set();
    ck[0]=ck[1]=0;
    for(int i=2;i<=N;i++) if(ck[i])
    {
        for(int j=2*i;j<=N;j=j+i){
            ck[j]=0;
        }
    }
}
int main()
{
    seive();
    int t;
    cin>>t;
    while(t--){
        int l,u;
        cin>>l>>u;
        vector<int>P;
        for(int i=l;i<=u;i++){
            if(ck[i]){
                P.push_back(i);
            }
        }
        map<int,int>mp;
        mp.clear();
        if(P.size()>1){
            for(int i=0;i<P.size()-1;i++){
                mp[P[i+1]-P[i]]++;
            }
        }
        int ans=0,d=0;
        bool flag=false;
        vector<pair<int,int> >pr;
        for(auto x:mp){
            pr.push_back({x.second,x.first});
        }
        sort(pr.begin(),pr.end());
        if(pr.size()>0){
            d=pr[pr.size()-1].first;
            if(pr.size()>1){
                if(pr[pr.size()-2].first==d){
                    flag=true;
                }
            }
        }
        if(d==0 || flag){
            printf("No jumping champion\n");
        }else{
            ans=pr[pr.size()-1].second;
            printf("The jumping champion is %d\n",ans);
        }
    }
}
