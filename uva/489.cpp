#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n && n>0){
        string a,b;
        cin>>a>>b;
        map<char,int>mp1,mp2;
        mp1.clear(),mp2.clear();
        for(int i=0;i<a.size();i++){
            mp1[a[i]]++;
        }
        bool flag=false,d=false,w=false;
        int cnt=0,g=0;
        for(int i=0;i<b.size();i++){
            if(mp1[b[i]]>0){
                g+=mp1[b[i]];
                mp1[b[i]]=-1;
            }else if(mp1[b[i]]==0){
                flag=true;
                cnt++;
            }
            if(g>=a.size() && d==false){
                w=true;
            }
            if(cnt>=7 && w==false){
                d=true;
            }
        }
        printf("Round %d\n",n);
        if(d){
            printf("You lose.\n");
        }else if(w){
            printf("You win.\n");
        }else{
            printf("You chickened out.\n");
        }
    }
}
