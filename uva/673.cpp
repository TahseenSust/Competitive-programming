/**
--------- -    |   |  /--  ----- ----- |\   |
    |    / \   |___| /__   |___  |___  | \  |
    |   /---\  |   |    /  |     |     |  \ |
    |  /     \ |   | __/   |____ |____ |   \|
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf scanf
#define pf printf
const int PRIME=10000000;
bitset<PRIME> prime_ck;
void sieve()
{
    prime_ck.set();
    int limit=sqrt(PRIME);
    prime_ck[0]=prime_ck[1]=0;
    for(int i=2;i<=limit;i++){
        if(prime_ck[i]){
            for(int j=i*i;j<=PRIME;j=j+i){
                prime_ck[j]=0;
            }
        }
    }
}
bool isprime(int n)
{
    return prime_ck[n];
}
bool isvowel(char n)
{
    if(n=='a'||n=='e'||n=='i'||n=='o'||n=='u') return true;
    return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        int ck=0,ln=0;
        string str;
        stack<char> S;
        //scanf("%*c");
        getline(cin,str);
        for(int i=0;i<str.size();i++){
            if(str[i]=='('||str[i]=='['){
                S.push(str[i]);
            }else if(!S.empty()){
                if(str[i]==')'&&S.top()=='(')
                    S.pop();
                else if(str[i]==']'&&S.top()=='[')
                    S.pop();
            }else if(str[i]==')'||str[i]==']'){
                S.push(str[i]);
            }
        }
        if(S.empty()){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}
