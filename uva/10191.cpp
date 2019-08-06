#include<bits/stdc++.h>
using namespace std;
#define bug cout<<"here\n";
int dif(pair<int,int>t1,pair<int,int>t2)
{
    int d1=0,d2=0;
    d1=t1.first*60+t1.second;
    d2=t2.first*60+t2.second;
    return d2-d1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int day=1;
    int n;
    while(cin>>n){
        pair<int,int>t1[110],t2[110];
        string apo;
        pair<pair<int,int>,int>ans;
        ans.second=-1;
        t2[0].first=10,t2[0].second=00;
        char bek;
        for(int i=1;i<=n;i++){
            cin>>t1[i].first>>bek>>t1[i].second>>t2[i].first>>bek>>t2[i].second;
            getline(cin,apo);
        }
        t1[n+1].first=18,t1[n+1].second=00;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(dif(t1[i],t1[j])<0){
                    swap(t1[i],t1[j]);
                    swap(t2[i],t2[j]);
                }
            }
        }
//        for(int i=0;i<=n+1;i++){
//            cout<<t1[i].first<<':'<<t1[i].second<<' '<<t2[i].first<<':'<<t2[i].second<<endl;
//        }
        //cout<<t1[1].first<<':'<<t1[1].second<<endl;
        int d;
        pair<int,int>ses={10,00},bz={0,0};
        for(int i=0;i<=n;i++){
            bz=max(bz,t2[i]);
            if(dif(bz,t1[i+1])>0){
                d=dif(bz,t1[i+1]);
                if(d>ans.second){
                    ans.second=d;
                    ans.first=bz;
                }
            }

        }
        if(ans.second<60)
            printf("Day #%d: the longest nap starts at %d:%0.2d and will last for %d minutes.\n",day,ans.first.first,ans.first.second,ans.second);
        else{
            int h=(ans.second/60),m;
            m=ans.second-h*60;
            printf("Day #%d: the longest nap starts at %d:%0.2d and will last for %d hours and %d minutes.\n",day,ans.first.first,ans.first.second,h,m);
        }
        day++;
        //printf("%d:%0.2d %d\n",t2[ans.first].first,t2[ans.first].second,ans.second);
    }
}
