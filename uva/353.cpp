#include<bits/stdc++.h>
using namespace std;
bool ck_pal(string str){
    string str2=str;
    reverse(str2.begin(),str2.end());
    return (str2==str);
}
int main()
{
    //freopen("in.txt","r",stdin);
    string str;
    while(cin>>str){
        map<string,bool>stor;
        int ans=0;
        for(int i=0;i<str.size();i++){
            for(int j=0;j<=i;j++){
                string tmp="";
                for(int k=j;k<=i;k++){
                    tmp+=str[k];
                }
                //cout<<"tmp is "<<tmp<<endl;
                bool d=ck_pal(tmp);
               // cout<<d<<endl;
                if(d){
                    if(stor[tmp]!=1){

                        stor[tmp]=1;
                        ans++;
                    }
                }
            }
        }
        printf("The string '%s' contains %d palindromes.\n",str.c_str(),ans);
        //cout<<ans<<endl;
    }
}
