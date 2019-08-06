#include<bits/stdc++.h>
using namespace std;

long long ara[1000000],n;
long long dp[1000000];
long long dir[1000000];

int main()
{
    long long x;
    string st;
    while(getline(cin,st)){
        n=0;
        if(st.size()==0){
            break;
        }
        stringstream ss(st);
        while(ss>>x){
            ara[n++]=x;
        }
        while(getline(cin,st)){

            if(st.size()==0){
                break;
            }
            stringstream ss(st);
            while(ss>>x){
                ara[n++]=x;
            }
        }
        int ix=0,s=0;
        memset(dir,-1,sizeof dir);
        dp[0]=0;
        for(int i=1;i<n;i++){
            if(ara[i]<ara[dp[0]]){
                dp[0]=i;
            }else if(ara[i]>ara[dp[s]]){
                dp[s+1]=i;
                dir[i]=dp[s];
                s++;
            }else{
                int l=-1,h=s,m;
                while(h-l>1){
                    m=(l+h)/2;
                    if(ara[dp[m]]>=ara[i]){
                        h=m;
                    }else{
                        l=m;
                    }
                }
                dp[h]=i;
                dir[i]=dp[h-1];
            }
        }
        cout<<s+1<<endl<<"-\n";
        vector<long long>ans;
        s=dp[s];
        while(s!=-1){
            ans.push_back(ara[s]);
            s=dir[s];
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
}
/**
-1
-2
-4
1
2
3
-1
*/
