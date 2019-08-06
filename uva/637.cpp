#include<bits/stdc++.h>
using namespace std;

string num_str(int n)
{
    string st="";
    while(n){
        st+=(n%10+'0');
        n/=10;
    }
    reverse(st.begin(),st.end());
    return st;
}
int main()
{
    int n,track;
    while(cin>>n && n){
        track=1;
        pair<int,int>page[30*2];
        for(int i=1;i<=ceil((double)n/4)*2;i++){
            if(i&1){
                page[i].second=track;
                track++;
            }else{
                page[i].first=track;
                track++;
            }
        }
        for(int i=ceil((double)n/4)*2;i>=1;i--){
            if(!(i&1)){
                page[i].second=track;
                track++;
            }else{
                page[i].first=track;
                track++;
            }
        }
        printf("Printing order for %d pages:\n",n);
        int p=1;
        for(int i=1;i<=ceil((double)n/4)*2;i++){
            if(i&1){
                string s1,s2;
                if(page[i].first>n) s1="Blank";
                if(page[i].first<=n) s1=num_str(page[i].first);
                if(page[i].second>n) s2="Blank";
                if(page[i].second<=n) s2=num_str(page[i].second);
                if(s1!="Blank" || s2!="Blank")
                    printf("Sheet %d, front: %s, %s\n",p,s1.c_str(),s2.c_str());
            }else{
                string s1,s2;
                if(page[i].first>n) s1="Blank";
                if(page[i].first<=n) s1=num_str(page[i].first);
                if(page[i].second>n) s2="Blank";
                if(page[i].second<=n) s2=num_str(page[i].second);
                if(s1!="Blank" || s2!="Blank")
                    printf("Sheet %d, back : %s, %s\n",p,s1.c_str(),s2.c_str());
                p++;
            }

        }
    }
}
