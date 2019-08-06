#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll limit=2000000000+1,p=2;
    map<int,int>mp; mp.clear();
    vector<ll>V;
    V.push_back(1);
    while(p<limit){
        if(!mp[p]){
            V.push_back(p);
            mp[p]++;
        }
        p*=2;
    }
    V.push_back(3);
    for(int i=1;i<V.size();i++){
        p=3*V[i];
        while(p<limit){
            if(!mp[p]){
                V.push_back(p);
                mp[p]++;
            }
            p*=3;
        }
    }
    V.push_back(5);
    for(int i=1;i<V.size();i++){
        p=5*V[i];
        while(p<limit){
            if(!mp[p]){
                V.push_back(p);
                mp[p]++;
            }
            p*=5;
        }
    }
    V.push_back(7);
    for(int i=1;i<V.size();i++){
        p=7*V[i];
        while(p<limit){
            if(!mp[p]){
                V.push_back(p);
                mp[p]++;
            }
            p*=7;
        }
    }
    sort(V.begin(),V.end());
    int n;
    while(cin>>n && n){
        string str;
        if(n%10==0){
            str="th";
        }else if(n%10==1){
            str="st";
        }else if(n%10==2){
            str="nd";
        }else if(n%10==3){
            str="rd";
        }else if(n%10==4 || n%10==5 || n%10==6 || n%10==7 || n%10==8 || n%10==9){
            str="th";
        }
        if(n%100==11 ||n%100==12 ||n%100==13 ||n%100==14){
            str="th";
        }
        printf("The %d%s humble number is %lld.\n",n,str.c_str(),V[n-1]);
    }
}
