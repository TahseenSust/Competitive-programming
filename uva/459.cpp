#include<bits/stdc++.h>
using namespace std;
int arr[50],n;
void init(int n)
{
    for(int i=0;i<=n;i++){
        arr[i]=i;
    }
}
void Union(int x,int y)
{
    int t=arr[x];
    for(int i=0;i<=n;i++){
        if(arr[i]==t){
            arr[i]=arr[y];
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    bool f=0;
    char x,y,e;
    string com;
    cin>>t;
    while(t--){
        cin>>e;
        n=e-'A';
        init(e-'A');
        cin.ignore();
        while(getline(cin,com)){
            if(com.size()==0)
                break;
            x=com[0];y=com[1];
            Union(x-'A',y-'A');
        }
        set<int>st;
        for(int i=0;i<=n;i++){
            st.insert(arr[i]);
        }
        if(f)
            cout<<'\n';
        f=1;
        cout<<st.size()<<endl;
    }
}
