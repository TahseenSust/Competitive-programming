/*
ID: tahseen1
PROG: dualpal
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

char to_char(int c)
{
    if(c >= 10) return c-10+'A';
    return c + '0';
}
string tobase(int num,int base)
{
    string ret;
    int div = base;
    while(div < num)
        div *= base;
    for(div /= base;;){
        ret += to_char(num/div);

        num = num % div;

        if(div < 2) break;

        div /= base;
    }

    return ret;
}


string reverse_str(string str)
{
    reverse(str.begin(),str.end());
    return str;
}
int main()
{
#ifndef ONLINE_JUDGE
    ofstream cout ("dualpal.out");
    ifstream cin ("dualpal.in");
#endif // ONLINE_JUDGE
    int n,s;
    cin>>n>>s;

    while(n){
        if(++s > 100000){
            break;
        }
        int num = 0;

        for(int j = 2; j <= 10; j++){
            string check = tobase(s,j);
            if( check == reverse_str(check) && ++num>=2){
                --n;
                cout<< s <<endl;
                break;
            }
        }
    }

}

