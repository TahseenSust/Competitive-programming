#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>m>>n){
        map<string,int>mp;
        string str;
        int x;
        while(m--){
            cin>>str>>x;
            mp[str]=x;
        }
        int sum=0;
        while(n--){
            sum=0;
            while(cin>>str){
                if(str=="."){
                    break;
                }
                sum+=mp[str];
            }
            cout<<sum<<endl;
        }

    }
}
