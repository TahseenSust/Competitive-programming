#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("11827.txt","r",stdin);
    int n,m;
    cin>>n;
    string s;
    getline(cin,s);
    while(n--){

        getline(cin,s);
        stringstream ss(s);
        int num;
        vector<int>V;
        while(ss>>num){
            V.push_back(num);
        }
        int mx=0;
        for(int i=0;i<V.size();i++){
            for(int j=i+1;j<V.size();j++){
                mx=max(mx,__gcd(V[i],V[j]));
            }
        }
        cout<<mx<<endl;
    }
}
