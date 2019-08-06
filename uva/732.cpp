#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define INF 1000000000
string str1,str2;
int cnt;
void solve(string m,string st,string ans,int i)
{

    if(m.size()==str2.size()){
        //cnt++;
        //cout<<m<<'.'<<endl;
        //cout<<m.size()<<'.'<<endl;
        if(m==str2){
            ans.erase(ans.size()-1);
            cout<<ans<<endl;
        }
        //return;
    }
    for(int j=0;j<m.size();j++){
        if(m[j]!=str2[j]){
            return;
        }
    }
    if(i<str1.size()){
        solve(m,st+str1[i],ans+"i ",i+1);
    }
    if(st.size()>0){
        //cout<<st<<'.'<<endl;
        m+=st[st.size()-1];
        st.erase(st.size()-1);
        solve(m,st,ans+"o ",i);
    }

}
int main ()
{
    while(cin>>str1>>str2){
        cout<<"[\n";
        solve("","","",0);
        cout<<"]\n";
    }
    //cout<<cnt<<endl;
}
