#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(cin>>str){
        string ans="";
        for(int i=0;i<str.size();i++){
            if(str[i]=='B'||str[i]=='F'||str[i]=='P'||str[i]=='V'){
                ans+="1";
                while(str[i+1]=='B'||str[i+1]=='F'||str[i+1]=='P'||str[i+1]=='V'){
                    i++;
                }
            }else if(str[i]=='C'||str[i]=='G'||str[i]=='J'||str[i]=='K'||str[i]=='Q'||str[i]=='S'||str[i]=='X'||str[i]=='Z'){
                ans+="2";
                while(str[i+1]=='C'||str[i+1]=='G'||str[i+1]=='J'||str[i+1]=='K'||str[i+1]=='Q'||str[i+1]=='S'||str[i+1]=='X'||str[i+1]=='Z'){
                    i++;
                }
            }else if(str[i]=='D'||str[i]=='T'){
                ans+="3";
                while(str[i+1]=='D'||str[i+1]=='T'){
                    i++;
                }
            }else if(str[i]=='L'){
                ans+="4";
                while(str[i+1]=='L'){
                    i++;
                }
            }else if(str[i]=='M'||str[i]=='N'){
                ans+="5";
                while(str[i+1]=='M'||str[i+1]=='N'){
                    i++;
                }
            }else if(str[i]=='R'){
                ans+="6";
                while(str[i+1]=='R'){
                    i++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
