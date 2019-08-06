#include<bits/stdc++.h>
using namespace std;
#define bug cout<<"done\n";
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,p,r,f=0;
    while(cin>>n>>p && (n && p)){
        double d;
        pair<int,double>ck={0,0};
        string strn,strp,str,ans;
        if(f) cout<<endl;
        f++;
        getline(cin,strn);
        for(int i=0;i<n;i++){
            getline(cin,strn);
        }
        for(int i=0;i<p;i++){
            getline(cin,str);
            cin>>d>>r;
            getline(cin,strp);
            for(int j=0;j<r;j++){
                getline(cin,strp);
            }
            if(r>ck.first){
                ck.first=r;
                ck.second=d;
                ans=str;
            }else if(r==ck.first && d<ck.second){
                ck.first=r;
                ck.second=d;
                ans=str;
            }
        }
        printf("RFP #%d\n",f);
        cout<<ans<<endl;
    }
}
