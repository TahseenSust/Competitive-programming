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
int power(int n,int p)
{
	int res=1;
	for(int i=0;i<p;i++){
		res*=n;
	}
	return res;
}
int main()
{
	double num[1500],sum,avg;
	int t,n;
	cin>>t;
	while(t--){
        sum=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>num[i];
            sum+=num[i];
        }
        avg=sum/((double)n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(num[i]>avg){
                cnt++;
            }
        }
        char p='%';
        printf("%.3lf%c\n",(((double)cnt)/((double)n))*100,p);
	}
}

