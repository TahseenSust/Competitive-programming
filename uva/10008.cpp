#include<bits/stdc++.h>
using namespace std;
struct dt{
    char c;
    int num;
};
bool cmp(dt a,dt b){
    if(a.num==b.num){
        return a.c<b.c;
    }
    return a.num>b.num;
}
int main()
{
    char str[1000000];
    dt ans[30];
    for(int i=0,j=65;i<26;i++,j++){
        ans[i].c=j;
    }
    int n;
    while(scanf("%d ",&n)!=EOF){
        int word[30]={0};
        for(int w=0;w<n;w++){
            scanf("%[^\n]s",str);
            scanf("%*c");
            for(int i=0;str[i];i++){
                if(str[i]>='a'&&str[i]<='z')
                    ans[str[i]-'a'].num++;
                else if(str[i]>='A'&&str[i]<='Z')
                    ans[str[i]-'A'].num++;
            }
        }
        sort(ans,ans+26,cmp);
        for(int i=0;i<26;i++){
            if(ans[i].num!=0)
                printf("%c %d\n",ans[i].c,ans[i].num);
        }

    }
}
