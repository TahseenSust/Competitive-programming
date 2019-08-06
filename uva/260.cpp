#include<bits/stdc++.h>
using namespace std;
char f[500][500];
int W=0,row,col;
bool v[500][500];
void dfs(int i,int j)
{
    //cout<<"dfs";
    if(i<0||j<0||i>=row||j>=col||v[i][j]){
        return;
    }
    if(f[i][j]=='w'&&j==col-1){
        W=1;
        return;
    }else if(f[i][j]=='w'){
        v[i][j]=true;
        dfs(i-1,j-1);
        dfs(i,j-1);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i+1,j+1);
        dfs(i+1,j);
    }else{
        return;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n,cn=1;;
    while(cin>>n&&n){
        row=n;col=n;
        cin.ignore();
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>f[i][j];
            cin.ignore();
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++)
//                cout<<f[i][j];
//            cout<<endl;
//        }
        for(int i=0;i<n;i++){
            if(f[i][0]=='w'){
                dfs(i,0);
                if(W){
                    break;
                }
            }
        }
        cout<<cn++<<' ';
        if(W==1){
            cout<<"W\n";
            W=0;
        }else{
            cout<<"B\n";
        }
        memset(f,' ',sizeof(f));
    }
}
/*
4
bbwb
wwbw
bbwb
bwww
4
bbwb
wwbw
bwwb
wwbb
0

*/
