#include<bits/stdc++.h>
bool p[20000010];
void sieve()
{
    int n=20000010;
    p[0]=1;
    p[1]=1;
    for(int i=4;i<n;i=i+2) p[i]=1;
    for(int i=3;i<n;i++){
        if(p[i]==0){
            for(int j=2*i;j<n;j=j+i) p[j]=1;
        }
    }
}
int o[100010];
void pa(){
    int j=1;
    for(int i=3;i<=20000010;i++){
        if(p[i]==0&&p[i+2]==0){
            o[j]=i;
            j++;
        }
    }
}
int main()
{
    sieve();
    pa();
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("(%d, %d)\n",o[n],o[n]+2);
    }
    return 0;

}
