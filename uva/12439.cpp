#include<bits/stdc++.h>
using namespace std;

int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
int val[]={11,12,1,2,3,4,5,6,7,8,9,10};
map<string,int>mp;

bool isleap(int y)
{
    if((y%4==0 && y%100!=0) || y%400==0) return 1;
    return 0;
}
int vis[40005];

void precal()
{
    mp["January"]=1;
    mp["February"]=2;
    mp["March"]=3;
    mp["April"]=4;
    mp["May"]=5;
    mp["June"]=6;
    mp["July"]=7;
    mp["August"]=8;
    mp["September"]=9;
    mp["October"]=10;
    mp["November"]=11;
    mp["December"]=12;
    int m1=1,m2=12,y1=1,y2=1200,cnt=0;

    for(int i=y1;i<=y2;i++){
        if(isleap(i)){
            vis[i]=1;
            cnt++;
        }
        vis[i]+=vis[i-1];
    }
}

int main()
{
    precal();
    int m1,m2,y1,y2,t,d1,d2;
    string mash1,mash2;
    char ch;
    cin>>t;

    for(int tc=1;tc<=t;tc++){

        cin>>mash1>>d1>>ch>>y1;
        cin>>mash2>>d2>>ch>>y2;

        m1=mp[mash1];
        m2=mp[mash2];

        if(m1>2) y1++;
        if(m2<2 || (m2==2 && d2<29)) y2--;
        int ans1=(y2/400)*97;
        y2=y2%400;
        ans1+=vis[y2];
        y1--;
        int ans2=(y1/400)*97;
        y1=y1%400;
        ans2+=vis[y1];
        printf("Case %d: %d\n",tc,ans1-ans2);
    }


}

