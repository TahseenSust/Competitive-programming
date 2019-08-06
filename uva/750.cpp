#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;


int x,y,cnt;

void backtrack(int c,int info[])
{
    if(c==9){
        cnt++;
        printf("%2d      ",cnt);
        cout<<info[1];
        for(int i=2;i<=8;i++){
            cout<<' '<<info[i];
        }
        cout<<endl;
        return;
    }
    if(c==y){
        backtrack(c+1,info);
    }else{
        for(int i=1;i<=8;i++){
            bool valid=1;
            for(int j=1;j<=8;j++){
                if(info[j]!=-1 && (info[j]==i || abs(c-j)==abs(info[j]-i))){
                    valid=0;
                    break;
                }
            }
            if(valid){
                info[c]=i;
                backtrack(c+1,info);
                info[c]=-1;
            }
        }
    }
}
int main()
{
    //freopen("in.txt","w",stdout);
    int t;
    cin>>t;

    while(t--){

        cnt=0;
        int info[10];
        memset(info,-1,sizeof info);
        cin>>x>>y;
        info[y]=x;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(1,info);
        if(t){
            cout<<endl;
        }
    }
}


