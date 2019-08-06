#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char word[100000];
    while(scanf("%[^\n]s",word)!=EOF){
        int cnt=0;
        scanf("%*c");
        for(int i=0;i<strlen(word);i++){
            if(word[i]>='A'&&word[i]<='Z'||word[i]>='a'&&word[i]<='z'){
                cnt++;

                for(int j=i+1;j<strlen(word);j++){
                    if(!(word[j]>='A'&&word[j]<='Z'||word[j]>='a'&&word[j]<='z')){
                        for(int k=j+1;k<strlen(word);k++){
                            if(word[k]>='A'&&word[k]<='Z'||word[k]>='a'&&word[k]<='z'){
                                i=k-1;
                                break;
                            }
                            if(k>=strlen(word)-1){
                                i=strlen(word);
                            }
                        }
                        break;
                    }
                    if(j>=strlen(word)-1||j+1>=strlen(word)-1){
                        i=strlen(word);
                        break;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
}
