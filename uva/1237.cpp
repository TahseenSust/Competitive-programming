#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    if(a.second.first==b.second.first){
        return a.second.second<=b.second.second;
    }
    return a.second.first<b.second.first;
}
int main()
{
    int t;cin>>t;
    while(t--){
        if(t){
            printf("\n");
        }
        int d,q,P;
        pair<string,pair<int,int>>p[10009];
        cin>>d;
        for(int i=0;i<d;i++){
            cin>>p[i].first>>p[i].second.first>>p[i].second.second;
            if(p[i].second.first>p[i].second.second){
                swap(p[i].second.first,p[i].second.second);
            }
        }
        sort(p,p+d,cmp);
        cin>>q;
        string ans;
        while(q--){
            cin>>P;
            int ok=0;
            for(int i=0;i<d && p[i].second.first<=P;i++){
                //cout<<p[i].first<<endl;
                if(P>=p[i].second.first && P<=p[i].second.second){
                    ok++;
                    ans=p[i].first;
                }
            }
            if(ok==0 || ok>1){
                printf("UNDETERMINED\n");
            }else{
                printf("%s\n",ans.c_str());
            }
        }
    }
}
