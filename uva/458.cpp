

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char sen[1000000];
    while(scanf("%[^\n]s",sen)!=EOF){
        scanf("%*c");
        for(int i=0;sen[i];i++){
            if(sen[i]!=' ')
                printf("%c",sen[i]-7);
        }
        printf("\n");
    }
}
