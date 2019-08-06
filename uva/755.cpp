#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    bool p=0;
    cin>>t;
    while(t--){
        if(p) cout<<endl;
        p=1;
        int n;
        cin>>n;
        string str;
        vector<string>V;
        map<string,int>mp;
        for(int i=0;i<n;i++){
            cin>>str;
            string num="";
            for(int j=0;j<str.size();j++){
                if(str[j]=='A'||str[j]=='B'||str[j]=='C'){
                    num+="2";
                }else if(str[j]=='D'||str[j]=='E'||str[j]=='F'){
                    num+="3";
                }else if(str[j]=='G'||str[j]=='H'||str[j]=='I'){
                    num+="4";
                }else if(str[j]=='J'||str[j]=='K'||str[j]=='L'){
                    num+="5";
                }else if(str[j]=='M'||str[j]=='N'||str[j]=='O'){
                    num+="6";
                }else if(str[j]=='P'||str[j]=='R'||str[j]=='S'){
                    num+="7";
                }else if(str[j]=='T'||str[j]=='U'||str[j]=='V'){
                    num+="8";
                }else if(str[j]=='W'||str[j]=='X'||str[j]=='Y'){
                    num+="9";
                }else if(str[j]>='0' && str[j]<='9'){
                    num+=str[j];
                }
                if(num.size()==3){
                    num+="-";
                }
            }
            if(mp[num]==0){
                V.push_back(num);
            }
            mp[num]++;
        }
        bool flag=0;
        sort(V.begin(),V.end());
        for(int i=0;i<V.size();i++){
            if(mp[V[i]]>1){
                flag=1;
                cout<<V[i]<<' '<<mp[V[i]]<<endl;
            }
        }
        if(!flag){
            cout<<"No duplicates.\n";
        }
    }
}
