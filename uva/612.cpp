#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int>a,pair<string,int>b)
{
    return a.second<b.second;
}
int main()
{
    int t;
    cin>>t;
    bool f=0;
    while(t--){
        if(f){
            printf("\n");
        }
        f=1;
        int s,n;
        pair<string,int>seq[115];
        cin>>s>>n;
        for(int i=0;i<n;i++){
            cin>>seq[i].first;
        }
        for(int i=0;i<n;i++){
            seq[i].second=0;
            for(int j=0;j<s;j++){
                for(int k=j;k<s;k++){
                    if(seq[i].first[j]>seq[i].first[k]){
                        seq[i].second++;
                    }
                }
            }
        }
        stable_sort(seq,seq+n,cmp);
        for(int i=0;i<n;i++){
            cout<<seq[i].first<<endl;
        }
    }
}
