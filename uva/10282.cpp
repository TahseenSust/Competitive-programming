#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,string>mp;
    string s,x;
    while(getline(cin,s)){
        vector<string>w;
        if(s.size()==0){
            break;
        }
        stringstream ss(s);
        while(ss>>x){
            w.push_back(x);
        }
        mp[w[1]]=w[0];
    }
    while(cin>>s){
        if(mp[s].size()==0){
            cout<<"eh\n";
        }else{
            cout<<mp[s]<<endl;
        }
    }

}

