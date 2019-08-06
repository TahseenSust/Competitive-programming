#include<bits/stdc++.h>
using namespace std;

bool dekh(string str1,string str2)
{
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    return (str1==str2);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string dic[115];
    string chk;
    int k=0;
    while(cin>>dic[k] && dic[k]!="XXXXXX"){
        k++;
    }
    while(cin>>chk && chk!="XXXXXX"){
        vector<string>ans;
        for(int i=0;i<k;i++){
            if(dekh(chk,dic[i])){
                ans.push_back(dic[i]);
            }
        }
        if(!ans.size()) cout<<"NOT A VALID WORD\n";
        else{
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<endl;
            }
        }
        cout<<"******\n";
    }
}
