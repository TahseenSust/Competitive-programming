#include<bits/stdc++.h>
using namespace std;
char tostring(int s)
{
    return s;
}

bool cmp(string a,string b)
{
    if(a.size()==b.size())
        return a<b;
    return a.size()<b.size();
}
int main()
{
    //freopen("out.txt","w",stdout);
    map<string,int>mp;
    int t=1;
    for(int _1='a';_1<='z';_1++){
        string s="";
        s=s+tostring(_1);
        mp[s];
        for(int _2=_1+1;_2<='z';_2++){
            string k=s;
            k=k+tostring(_2);
            mp[k];
            for(int _3=_2+1;_3<='z';_3++){
                string q=k;
                q=q+tostring(_3);
                mp[q];
                for(int _4=_3+1;_4<='z';_4++){
                    string p=q;
                    p=p+tostring(_4);
                    mp[p];
                    for(int _5=_4+1;_5<='z';_5++){
                        string o=p;
                        o=o+tostring(_5);
                        mp[o];
                    }
                }
            }
        }
    }
    vector<string>V;
    for(auto s:mp){
        V.push_back(s.first);
    }
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size();i++){
        mp[V[i]]=i+1;
    }
    string str;
    while(cin>>str){
        cout<<mp[str]<<endl;
    }
}
