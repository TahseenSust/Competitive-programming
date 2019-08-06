#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;

        int sum=0,x=n;
        map<int,int>mp;
        mp[n]++;
        while(1){
            if(sum==1 || mp[sum]>1){
                break;
            }
            sum=0;
            while(x){
                sum+=(x%10)*(x%10);
                x/=10;
            }
            mp[sum]++;
            x=sum;
            //cout<<x<<endl;
            //getchar();
        }
        printf("Case #%d: %d is ",tc,n);
        cout<<(sum==1?"a Happy number.":"an Unhappy number.")<<endl;
    }
}
