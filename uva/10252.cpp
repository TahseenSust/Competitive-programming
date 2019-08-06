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
bool isvowel(char n)
{
    if(n=='a'||n=='e'||n=='i'||n=='o'||n=='u') return true;
    return false;
}
int power(int n,int p)
{
	int res=1;
	for(int i=0;i<p;i++){
		res*=n;
	}
	return res;
}
int lcm(int a,int b)
{
	return (a/__gcd(a,b))*b;
}
int main()
{
    //freopen("input.txt","r",stdin);
    string a,b;
    while(getline(cin,a)){
        //getline(cin,b);
        getline(cin,b);
        int f1[27]={0},f2[27]={0};
        for(int i=0;i<a.size();i++){
            f1[a[i]-'a']++;
        }
        for(int i=0;i<b.size();i++){
            f2[b[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<min(f1[i],f2[i]);j++){
                printf("%c",i+'a');
            }
        }
        cout<<'\n';
    }
}
