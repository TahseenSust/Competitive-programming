#include<bits/stdc++.h>
using namespace std;
int main()
{
    char num[100];
    int powe;
    while(scanf("%s",num)&&strcmp(num,"0")!=0){
        powe=strlen(num);
        int res=0;
        for(int i=0;i<powe;i++){
            res=res+((num[i]-'0')*(((int)pow(2,powe-i))-1));
        }
        printf("%d\n",res);
    }
}
