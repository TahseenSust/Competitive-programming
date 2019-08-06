#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int n,x,y,cn=1;
    while(cin>>str){
        cin>>n;
        printf("Case %d:\n",cn++);
        while(n--){
            cin>>x>>y;
            bool f=0;
            for(int i=min(x,y)+1;i<=max(x,y);i++){
                if(str[i]!=str[i-1]){
                    cout<<"No\n";
                    f=1;
                    break;
                }
            }
            if(!f){
                cout<<"Yes\n";
            }
        }
    }
}
