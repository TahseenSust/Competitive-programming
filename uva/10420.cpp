#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    string str;
    map<string,set<string>>mp;
    cin>>n;
    cin.ignore();

    while(n--){
        getline(cin,str);
        stringstream ss(str);
        string coun,name;
        ss>>coun;
        while(ss>>str){
            name=name+str;
        }
        mp[coun].insert(name);
    }
    for(auto x:mp){
        cout<<x.first<<' '<<x.second.size()<<endl;
    }
}
