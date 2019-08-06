#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,s,e,r;
    while(cin>>n>>m){
        if(n==0 && m==0){
            return 0;
        }
        bool flag;
        flag=true;
        bitset<1000010>time;
        time.reset();
        while(n--){
            cin>>s>>e;
            for(int i=s;i<e;i++){
                if(time[i]==1){
                    flag=false;
                }
                time[i]=1;
            }
        }
        while(m--){
            cin>>s>>e>>r;
            int t=0;
            while(1){
                for(int i=s+t;i<e+t && i<=1000000;i++){
                    if(time[i]==1){
                        flag=false;
                    }
                    time[i]=1;
                }
                t+=r;
                if(t>1000000)
                    break;
            }
        }
        if(flag){
            cout<<"NO CONFLICT\n";
        }else{
            cout<<"CONFLICT\n";
        }
    }
}
