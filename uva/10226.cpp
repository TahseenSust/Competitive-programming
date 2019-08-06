#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    string str;
    getline(cin,str);
    while(t--){
        map<string,int>mp;
        mp.clear();
        int cnt=0;
        getline(cin,str);
        if(str!=""){
            mp[str]++;
            cnt++;
        }
        while(getline(cin,str) && str!=""){
            mp[str]++;
            cnt++;
        }
        if(!t){
            cnt--;
        }
        vector<pair<string,double>>vec;
        for(auto x:mp){
            double per=((double)x.second/(double)cnt)*100.0;
            vec.push_back({x.first,per});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            cout<<vec[i].first<<' '<<setprecision(4)<<fixed<<vec[i].second<<endl;
        }
        if(t){
            cout<<endl;
        }
    }
}

