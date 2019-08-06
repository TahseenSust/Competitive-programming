#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string s,t;
    while(cin>>s>>t){
        int cnt=0;

        for(int i=0,j=0;i<t.size();i++){
            if(s[j]==t[i]){
                cnt++;
                j++;
            }
        }
        if(cnt==s.size()){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}
