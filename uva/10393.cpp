#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{


    vector<string>finger;
    finger.push_back("");
    finger.push_back("qaz");
    finger.push_back("wsx");
    finger.push_back("edc");
    finger.push_back("rfvtgb");
    finger.push_back(" ");
    finger.push_back(" ");
    finger.push_back("yhnujm");
    finger.push_back("ik,");
    finger.push_back("ol.");
    finger.push_back("p;/");

    int f,n,x;
    while(cin>>f>>n){

        map<char,bool>mp;

        for(int i=0;i<f;i++){
            cin>>x;
            for(int j=0;j<finger[x].size();j++){
                char ch=finger[x][j];
                mp[ch]=1;
            }
        }

        string str;
        vector<string>word;
        map<string,bool>chk;
        int sz=0,len;
        for(int i=0;i<n;i++){
            cin>>str;
            if(chk[str]){
                continue;
            }
            chk[str]=1;
            bool flag=1;
            for(int j=0;j<str.size();j++){
                if(mp[str[j]]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                len=str.size();
                sz=max(sz,len);
                word.push_back(str);
            }
        }

        sort(word.begin(),word.end());

        vector<string>ans;

        for(int i=0;i<word.size();i++){
            if(word[i].size()==sz){
                ans.push_back(word[i]);
            }
        }

        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
}
