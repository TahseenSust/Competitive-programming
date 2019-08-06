#include<bits/stdc++.h>
using namespace std;
long long fact(long long n){
    long long f=1;
    for(int i=1;i<=n;i++){
        f=f*i;
    }
    return f;
}
int main()
{
    int T,cn=0;
    scanf("%d",&T);
    while(T--){
        char word[25];
        scanf(" %s",word);
        long long len=(long long)strlen(word);
        sort(word,word+len);
        char pre=word[0];
        long long cnt[25],k=0;
        for(int i=0;i<25;i++) cnt[i]=1;
        for(int i=1;i<len;i++){
            if(word[i]==pre){
                cnt[k]++;
            }else{
                k++;
                pre=word[i];
            }
        }
        long long o=1;
        for(int i=0;i<=k;i++){
            o=o*fact(cnt[i]);
        }
        printf("Data set %d: %lld\n",++cn,(fact(len))/o);
    }
}
