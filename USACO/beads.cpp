/*
ID: tahseen1
PROG: beads
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        ofstream cout ("beads.out");
        ifstream cin ("beads.in");
    #endif // ONLINE_JUDGE
    int n,ans=0,p;
    cin>>n;
    cin.ignore();
    char nek[2*n+10],tnek[2*n+10];
    cin>>nek;
    strcpy(tnek,nek);
    strcat(nek,tnek);
    int ck=0;
    for(int i=ck;i<n;i++){
        p=0;
        int j=i,dek;
        set<char> b;
        b.clear();
        while(j>=0&&b.size()<=1){
            if(nek[j]!='w'){
                b.insert(nek[j]);
            }
            j--;
            if(b.size()<=1)
                p++;
        }
        j=i+1;
        b.clear();
        while(nek[j]&&b.size()<=1&&p<n){
            if(nek[j]!='w'){
                b.insert(nek[j]);
            }
            j++;
            if(b.size()<=1)
                p++;
        }
        ans=max(ans,p);
    }
    cout<<ans<<endl;
}
