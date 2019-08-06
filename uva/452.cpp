#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD=1000000000+7;


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    string str;

    getline(cin,str);
    getline(cin,str);

    bool flag=0;
    while(t--){
        if(flag) cout<<endl;
        flag=1;
        int tim[50]={0};
        int G[100][100]={0};
        bool taken[100]={0};
        int degree[100]={0};
        vector<int>ans;
        bool mp[100]={0};
        while(getline(cin,str)){
            if(str.size()==0) break;
            int u=str[0];
            int d=0,j=2;
            while(str[j]>='0' && str[j]<='9'){
                d=d*10+(str[j]-'0');
                j++;
            }
            j++;
            tim[u-'A']=d;
            mp[u-'A']=1;
            for(int i=j;i<str.size();i++){
                int v=str[i]-'A';
                mp[v]=1;
                G[v][u-'A']=1;
                degree[u-'A']++;
            }
        }
        int total=0;
        for(int i=0;i<26;i++){
            int w=-1;
            int mn=INT_MAX;
            for(int j=0;j<26;j++){
                if(!taken[j] && degree[j]==0){
                    if(tim[j]<mn){
                        w=j;
                        mn=tim[j];
                    }
                }
            }
            if(w==-1) break;
            taken[w]=1;
            total+=mn;
            for(int j=0;j<26;j++){
                if(taken[j]==0 && G[w][j]==1){
                    degree[j]--;
                }else if(degree[j]==0){
                    tim[j]-=mn;
                }
            }
        }

        cout<<total<<endl;
    }

}
