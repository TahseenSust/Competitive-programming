#include<bits/stdc++.h>
using namespace std;
int main()
{

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,d=0;
    while(cin>>n && n){
        if(d){
            printf("\n");
        }
        d=1;
        bool f=0,nim=1;
        for(int i=1;i<=99999;i++){
            if(i%n==0){
                int p=i;
                int q=i/n;
                string s1="",s2="";
                nim=1;
                while(p){
                    s1+=((p%10)+'0');
                    p/=10;
                }
                reverse(s1.begin(),s1.end());
                while(q){
                    s2+=((q%10)+'0');
                    q/=10;
                }
                reverse(s2.begin(),s2.end());
                for(int i=s1.size();i<5;i++){
                    s1="0"+s1;
                }
                for(int i=s2.size();i<5;i++){
                    s2="0"+s2;
                }
                //cout<<s1<<' '<<s2<<endl;
                map<int,int>mp;
                mp.clear();
                for(int i=0;i<s1.size();i++){
                    mp[s1[i]]++;
                    mp[s2[i]]++;
                    if(mp[s1[i]]>1 || mp[s2[i]]>1){
                        nim=0;
                        break;
                    }
                }
                if(nim==0){
                    continue;
                }
                printf("%s / %s = %d\n",s1.c_str(),s2.c_str(),n);
                f=1;
            }

        }
        if(f==0){
            printf("There are no solutions for %d.\n",n);
        }
    }
}
