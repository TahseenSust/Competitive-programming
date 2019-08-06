#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD=1000000000+7;

vector<int>box;
char ch;
int j=1;
map<char,int>mp;
map<char,int>mp2;

void solve(int degree[],int graph[][100],bool taken[],string str)
{
    for(int i=1;i<j;i++){
        if(degree[i]==0 && !taken[i]){
            taken[i]=1;
            for(int k=1;k<j;k++){
                if(graph[i][k]==1){
                    graph[i][k]=-1;
                    degree[k]--;
                }
            }
            ch=mp2[i];
            solve(degree,graph,taken,str+ch);
            taken[i]=0;
            for(int k=1;k<j;k++){
                if(graph[i][k]==-1){
                    graph[i][k]=1;
                    degree[k]++;
                }
            }
        }
    }
    if(str.size()==j-1)
        cout<<str<<endl;
}

/**
v w x y z
v y x v z v w v
*/
int main()
{
    //freopen("out.txt","w",stdout);
    string str;
    bool flag=0;
    while(getline(cin,str)){
        j=1;
        sort(str.begin(),str.end());
        mp.clear();
        mp2.clear();
        box.clear();
        if(flag) cout<<endl;
        flag=1;
        for(int i=0;i<str.size();i++){
            if(islower(str[i])){
                mp[str[i]]=j;
                mp2[j]=str[i];
                box.push_back(j);
                j++;
            }
        }
        str.clear();
        int graph[100][100]={0},degree[100]={0};
        getline(cin,str);
        char u,v;
        bool f1=0,f2=0;
        for(int i=0;i<str.size();i++){
            if(islower(str[i])){
                if(f1==0){
                    f1=1;
                    u=str[i];
                }else if(f2==0){
                    f2=1;
                    v=str[i];
                }
            }
            if(f1 && f2){
                graph[mp[u]][mp[v]]=1;
                degree[mp[v]]++;
                f1=f2=0;
            }
        }
        bool taken[100]={0};

        solve(degree,graph,taken,"");
        str.clear();
    }
}
