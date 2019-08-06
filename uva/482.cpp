#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    bool f=0;
    cin>>tc;
   // getchar();
    while(tc--){
        int j,i=0,x;
        string y;
        vector<int>in;
        string arr[100000];
        char l=' ';
        while(l==' '){
            scanf("%d%c",&x,&l);
            in.push_back(x);
            i++;
        }
        for(j=0;j<i;j++){
            cin>>arr[in[j]-1];
        }
        if(f) cout<<'\n';
        f=1;
        for(j=0;j<i;j++){
            cout<<arr[j]<<endl;
        }
    }
}
