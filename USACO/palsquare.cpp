/*
ID: tahseen1
PROG: palsquare
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
    ofstream cout ("palsquare.out");
    ifstream cin ("palsquare.in");
#endif // ONLINE_JUDGE
    int b,tmp;
    cin>>b;

    for(int i=1; i<=300; i++)
    {
        string n = tobase(i,b), n2 =tobase(i*i,b);
        if(n2 == reverse_str(n2))
        {
            cout<<n<<' '<<n2<<endl;
        }
    }

}

