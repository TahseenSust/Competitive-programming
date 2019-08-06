#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


int main()
{
    char country[55];

    for(int i=1;i<=26;i++){
        country[i]='A'+i-1;;
    }
    for(int i=27;i<=50;i++){
        country[i]='a'+i-27;
    }


    int n,f=0;
    while(cin>>n){

        if(f) cout<<endl;
        f=1;

        cout<<n<<' '<<2<<' '<<n<<endl;


        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<country[i]<<country[j]<<endl;
            }
            cout<<endl;
        }

    }

}
