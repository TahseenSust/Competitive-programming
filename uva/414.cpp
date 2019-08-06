#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n && n){
        int s[20],m=50;
        string str;
        getline(cin,str);
        for(int i=0;i<n;i++){
            getline(cin,str);
            int b=0;
            for(int j=0;j<25;j++){
                if(str[j]==' '){
                    b++;
                }
            }
            s[i]=b;
            m=min(m,s[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            s[i]-=m;
            ans+=s[i];
        }
        cout<<ans<<endl;
    }
}
