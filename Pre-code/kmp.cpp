#include<bits/stdc++.h>
using namespace std;

int failure[1000005];

void failure_func(string str)
{
    int m=str.size();

    failure[0]=0;
    failure[1]=0;

    for(int i=2;i<=m;i++){

        int j=failure[i-1];

        while(1){
            if(str[j]==str[i-1]){
                failure[i]=j+1;
                break;
            }

            if(j==0){
                failure[i]=0;
                break;
            }

            j=failure[j];

        }
    }
}


int kmp(string text,string pattern)
{
    int n=text.size();
    int m=pattern.size();

    int i=0;
    int j=0;
    int ans=0;

    while(1){
        if(j==n){
            break;
        }

        if(text[j]==pattern[i]){
            i++;j++;
            if(i==m){
                ans++;
                i=failure[i];
            }
        }else{
            if(i==0){
                j++;
            }else{
                i=failure[i];
            }
        }
    }

    return ans;
}

int main()
{
    int t;
    string text,pattern;

    scanf("%d",&t);

    for(int tc=1;tc<=t;tc++){
        cin>>text>>pattern;
        memset(failure,0,sizeof failure);
        failure_func(pattern);
        printf("Case %d: %d\n",tc,kmp(text,pattern));
    }
}

