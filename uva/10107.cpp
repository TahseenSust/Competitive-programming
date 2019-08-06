#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> ar;
    while(cin>>n){
        ar.push_back(n);
        sort(ar.begin(),ar.end());
        int mid=ar.size()/2;
        if(ar.size()%2==1){
            cout<<ar[mid]<<endl;
        }else{
            int p=(ar[mid]+ar[mid-1])/2;
            cout<<p<<endl;
        }
    }
}
