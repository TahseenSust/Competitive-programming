#include<bits/stdc++.h>
using namespace std;

string lower(string str)
{
    string re="";
    for(int i=0;i<str.size();i++){
        re+=tolower(str[i]);
    }
    return re;
}
int main()
{
    string str[100000];
    vector<string>ans;
    map<string,int>mp;
    int i=0;
    while(cin>>str[i] && str[i]!="#"){
        string ck=lower(str[i]);
        sort(ck.begin(),ck.end());
        mp[ck]++;
        i++;
    }
    for(int j=0;j<i;j++){
        string ck=lower(str[j]);
        sort(ck.begin(),ck.end());
        if(mp[ck]<=1){
            ans.push_back(str[j]);
            mp[ck]=INT_MAX;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
