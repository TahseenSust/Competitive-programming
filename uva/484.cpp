#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    map<string,int>mp;
        list<string>mylist;
    while(getline(cin,str)){
        stringstream ss(str);
        string x;
        while(ss>>x){
            if(mp[x]==0)
                mylist.push_back(x);
            mp[x]++;

        }
    }
    for(auto d:mylist){
        cout<<d<<' '<<mp[d]<<endl;
    }
}
