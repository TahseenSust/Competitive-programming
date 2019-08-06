#include<bits/stdc++.h>
using namespace std;

string lower(string str)
{
    string re="";
    for(int i=0;i<str.size();i++){
        if(str[i]!=' ')
            re+=str[i];
    }
    sort(re.begin(),re.end());
    return re;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string str[150];
    int t,f=0; cin>>t;
    getline(cin,str[0]);
    getline(cin,str[0]);
    while(t--){
        if(f){
            printf("\n");
        }
        f=1;
        int k=0;
        while(getline(cin,str[k]) && str[k].size()!=0){
            k++;
        }
        vector<pair<string,string>>ans;
        for(int i=0;i<k;i++){
            string ck1=lower(str[i]);
            for(int j=i+1;j<k;j++){
                string ck2=lower(str[j]);
                if(ck1==ck2){
                    string s1=str[i],s2=str[j];
                    if(s1>s2){
                        swap(s1,s2);
                    }
                    ans.push_back({s1,s2});
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            printf("%s = %s\n",ans[i].first.c_str(),ans[i].second.c_str());
        }
    }
}
