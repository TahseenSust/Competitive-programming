#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(str=="1" || str=="4" || str=="78"){
            cout<<"+\n";
        }else if(str[str.size()-2]=='3' && str[str.size()-1]=='5'){
            cout<<"-\n";
        }else if(str[0]=='9' && str[str.size()-1]=='4'){
            cout<<"*\n";
        }else{
            cout<<"?\n";
        }
    }
}
