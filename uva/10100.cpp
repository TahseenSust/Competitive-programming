#include<bits/stdc++.h>
using namespace std;

vector<string>v1,v2;

int dp[1002][1002];

int solve(int i,int j)
{
    if(i==v1.size() || j==v2.size()) return 0;
    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    if(v1[i]==v2[j]){
        ret=solve(i+1,j+1)+1;
    }else{
        ret=max(solve(i+1,j),solve(i,j+1));
    }
    return ret;
}
int main()
{
    int tc=1;
    string str1,str2;

    while(getline(cin,str1)){
        getline(cin,str2);
        printf("%2d. ",tc++);
        if(str1.size()==0 || str2.size()==0){
            cout<<"Blank!\n";
        }else{
            for(int i=0;i<str1.size();i++){
                if((str1[i]>='a' && str1[i]<='z') || (str1[i]>='A' && str1[i]<='Z') || (str1[i]>='0' && str1[i]<='9'))continue;
                str1[i]=' ';
            }
            for(int i=0;i<str2.size();i++){
                if((str2[i]>='a' && str2[i]<='z') || (str2[i]>='A' && str2[i]<='Z') || (str2[i]>='0' && str2[i]<='9'))continue;
                str2[i]=' ';
            }
            stringstream s1(str1);
            v1.clear();
            v2.clear();
            while(s1>>str1){
                v1.push_back(str1);
            }
            stringstream s2(str2);
            while(s2>>str1){
                v2.push_back(str1);
            }
            memset(dp,-1,sizeof dp);
            int mx=solve(0,0);
            printf("Length of longest match: %d\n",mx);
        }
    }


}
