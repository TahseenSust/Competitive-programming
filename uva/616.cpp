#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,ans;
    while(cin>>n && n>=0){
        ans=0;
        for(int i=1;i<=10;i++){
            if(n%i==1){
                int t=n,cnt=0;
                while(t%i==1){
                    t=t-((t-1)/i)-1;
                    cnt++;
                }
                //cout<<t<<endl;
                if(t%i==0 && i==cnt){
                    ans=i;
                }
            }
        }
        if(ans)
            printf("%d coconuts, %d people and 1 monkey\n",n,ans);
        else
            printf("%d coconuts, no solution\n",n,ans);
    }

}
