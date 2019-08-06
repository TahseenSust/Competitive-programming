#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        string str;
        while(n--){
            cin>>str;
            sort(str.begin(),str.end());
            do{
                cout<<str<<endl;
            }while(next_permutation(str.begin(),str.end()));
            cout<<endl;
        }
    }
}
