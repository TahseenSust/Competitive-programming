#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;



void topsort(map<string,int>node,string str[],vector<int>G[],int indegree[],int n)
{

    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                cout<<' '<<str[i];
                indegree[i]=-1;
                for(auto x:G[i]){
                    indegree[x]--;
                }
                break;
            }
        }
    }
    cout<<".\n\n";
}




int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,tc=1;
    while(cin>>n){
        map<string,int>node;
        string str[105];
        vector<int>G[105];
        int indegree[105]={};

        string s1,s2;
        for(int i=1;i<=n;i++){
            cin>>s1;
            node[s1]=i;
            str[i]=s1;
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>s1>>s2;
            int u=node[s1],v=node[s2];
            G[u].push_back(v);
            indegree[v]++;
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",tc++);
        topsort(node,str,G,indegree,n);
    }
}
