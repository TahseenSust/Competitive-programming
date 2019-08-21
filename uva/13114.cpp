#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans[102];

void cal(int pos)
{
    for(int i=1;i<=1000;i++){
        int line[200]={0};
        line[pos]=1;
        int baki=100,r=0,s=1;
        while(baki>1){
            if(r==0){
                for(int j=1;j<=i;){
                    if(line[s]!=-1){
                        j++;
                    }
                    if(j>i) break;
                    s++;
                    if(s>100){
                        s=1;
                    }
                }
                line[s]=-1;
                baki--;
                while(line[s]==-1){
                    s++;
                    if(s>100){
                        s=1;
                    }
                }
                r=!r;
            }else{
                for(int j=1;j<=i;){
                    if(line[s]!=-1){
                        j++;
                    }
                    if(j>i) break;
                    s--;
                    if(s<=0){
                        s=100;
                    }
                }
                line[s]=-1;
                baki--;
                while(line[s]==-1){
                    s--;
                    if(s<=0){
                        s=100;
                    }
                }
                r=!r;
            }
            //for(int i=1;i<=100;i++) cout<<line[i]<<' ';
            //cout<<endl;
        }
        if(line[pos]==1){
            ans[pos]=i;
            break;
        }
    }
}


int main(int argc, char const *argv[])
{
    for(int i=1;i<=100;i++) cal(i);
    int n;

    while(scanf("%d",&n) && n){
        printf("%d\n",ans[n]);
    }

}
