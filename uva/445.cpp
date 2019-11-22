#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str;

    bool flag=0;
    while(cin>>str){
        if(flag) cout<<endl;
        flag=1;

        int d=0;
        char ch;

        for(int i=0;i<str.size();i++){
            if(str[i]>='0' && str[i]<='9'){
                d+=(str[i]-'0');
            }else{
                if(str[i]=='!'){
                    cout<<endl;
                }
                while(d){
                    if(str[i]=='!'){
                        cout<<endl;
                    }else if(str[i]=='b'){
                        cout<<' ';
                    }else{
                        cout<<str[i];
                    }
                    d--;
                }
            }
        }
        cout<<endl;
        getline(cin,str);
        while(getline(cin,str)){
            if(str.size()==0) break;
            d=0;
            for(int i=0;i<str.size();i++){
                if(str[i]>='0' && str[i]<='9'){
                    d+=(str[i]-'0');
                }else{
                    if(str[i]=='!'){
                        cout<<endl;
                    }
                    while(d){
                        if(str[i]=='!'){
                            cout<<endl;
                        }else if(str[i]=='b'){
                            cout<<' ';
                        }else{
                            cout<<str[i];
                        }
                        d--;
                    }
                }
            }
            cout<<endl;
        }

    }



}

