#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define INF 1000000000
typedef long long ll;
typedef unsigned long long ull;

string add(string a,string b)
{
    string c;
    if(a.size()<b.size()){
        swap(a,b);
    }
    int sz=min(a.size(),b.size());
    int carry=0;
    c="";
    for(int i=0;i<sz;i++){
        int x=a[a.size()-i-1]-'0';
        int y=b[b.size()-i-1]-'0';
        c+=((x+y+carry)%10)+'0';
        carry=(x+y+carry)/10;
    }
    for(int i=sz;i<a.size();i++){
        int x=a[a.size()-i-1]-'0';
        c+=((x+carry)%10)+'0';
        carry=(x+carry)/10;
    }
    while(carry){
        c+=(carry%10)+'0';
        carry/=10;
    }
    reverse(c.begin(),c.end());
    return c;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string fib[5005],c;
    fib[0]="0";
    fib[1]="1";
    for(int i=2;i<=5000;i++){
        fib[i]=add(fib[i-1],fib[i-2]);
    }
    while(cin>>n){
        cout<<"The Fibonacci number for "<<n<<" is "<<fib[n]<<endl;
    }
}
