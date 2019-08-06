#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(cin>>str){
        list<char>ans;
        for(int i=0;i<str.size();i++){
            if(str[i]!='[' && str[i]!=']'){
                ans.push_back(str[i]);
            }
            if(str[i]=='['){
                i++;
                list<char>tmp;
                while(str[i]!='[' && str[i]!=']' && i<str.size()){
                    tmp.push_back(str[i]);
                    i++;
                }
                list<char>::iterator it;
                it=ans.begin();
                ans.splice(it,tmp);
                i--;
            }
        }
        for(auto x:ans)
            cout<<x;
        cout<<endl;
    }
}

/**
This_is_a_[Beiju]_text
BeijuThis_is_a__text

This_is_a_[Be[iju]_text
ijuBeThis_is_a__text

This_is_a_[Be[ij]u]_text
ijBeThis_is_a_u_text

*/
