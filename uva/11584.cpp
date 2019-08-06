#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=100005;

string str;

bool palin[1005][1005];

int dp[1005];

int solve(int s)
{
    if(s==str.size()){
        return 0;
    }
    if(dp[s]!=-1){
        return dp[s];
    }
    int re=INT_MAX;
    for(int i=s;i<str.size();i++){
        if(palin[s][i]){
            re=min(re,1+solve(i+1));
        }
    }
    return dp[s]=re;
}

int main()
{
    //freopen("uva.txt","w",stdout);
    int t;

    scanf("%d",&t);

    for(int tc=1;tc<=t;tc++){

        cin>>str;
        string tmp1,tmp2;
        int l,r;

        memset(palin,false,sizeof palin);

        for(int i=0;i<str.size();i++){
            l=r=i;

            while(str[l]==str[r]){
                palin[l][r]=1;
                l--,r++;
                if(l<0 || r>=str.size()){
                    break;
                }
            }
        }
        for(int i=0;i<str.size()-1;i++){
            l=i;
            r=i+1;

            while(str[l]==str[r]){
                palin[l][r]=1;
                l--,r++;
                if(l<0 || r>=str.size()){
                    break;
                }
            }
        }

    //    for(int i=0;i<str.size();i++){
    //        for(int j=0;j<str.size();j++){
    //            cout<<palin[i][j]<<' ';
    //        }
    //        cout<<endl;
    //    }

        memset(dp,-1,sizeof dp);

        printf("%d\n",solve(0));
    }

}
