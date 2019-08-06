#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int t;

    cin>>t;

    while(t--){

        int k;

        cin>>k;

        map<char,double>mp;
        char x;
        double val;
        while(k--){
            cin>>x>>val;
            mp[x]=val;
        }
        int m;
        cin>>m;
        string str;
        double ans=0;
        getline(cin,str);
        while(m--){
            getline(cin,str);

            stringstream ss(str);

            string s;

            while(ss>>s){
                for(int i=0;i<s.size();i++)
                    ans+=mp[s[i]];
            }
        }
        printf("%.2f$\n",ans/100.00);
    }
}
