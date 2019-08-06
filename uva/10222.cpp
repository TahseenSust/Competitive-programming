#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    char w[1000000],ans[1000000];
    while(scanf("%[^\n]s",w)!=EOF){
        scanf("%*c");
        for(int i=0;w[i];i++){
            if(w[i]=='e'||w[i]=='E'){
                ans[i]='q';
            }else if(w[i]=='d'||w[i]=='D'){
                ans[i]='a';
            }else if(w[i]=='c'||w[i]=='C'){
                ans[i]='z';
            }else if(w[i]=='r'||w[i]=='R'){
                ans[i]='w';
            }else if(w[i]=='f'||w[i]=='F'){
                ans[i]='s';
            }else if(w[i]=='v'||w[i]=='V'){
                ans[i]='x';
            }else if(w[i]=='t'||w[i]=='T'){
                ans[i]='e';
            }else if(w[i]=='g'||w[i]=='G'){
                ans[i]='d';
            }else if(w[i]=='b'||w[i]=='B'){
                ans[i]='c';
            }else if(w[i]=='y'||w[i]=='Y'){
                ans[i]='r';
            }else if(w[i]=='h'||w[i]=='H'){
                ans[i]='f';
            }else if(w[i]=='n'||w[i]=='N'){
                ans[i]='v';
            }else if(w[i]=='u'||w[i]=='U'){
                ans[i]='t';
            }else if(w[i]=='j'||w[i]=='J'){
                ans[i]='g';
            }else if(w[i]=='m'||w[i]=='M'){
                ans[i]='b';
            }else if(w[i]=='i'||w[i]=='I'){
                ans[i]='y';
            }else if(w[i]=='k'||w[i]=='K'){
                ans[i]='h';
            }else if(w[i]==','||w[i]=='<'){
                ans[i]='n';
            }else if(w[i]=='o'||w[i]=='O'){
                ans[i]='u';
            }else if(w[i]=='l'||w[i]=='L'){
                ans[i]='j';
            }else if(w[i]=='.'||w[i]=='>'){
                ans[i]='m';
            }else if(w[i]=='p'||w[i]=='P'){
                ans[i]='i';
            }else if(w[i]==';'||w[i]==':'){
                ans[i]='k';
            }else if(w[i]=='/'||w[i]=='?'){
                ans[i]=',';
            }else if(w[i]=='['||w[i]=='{'){
                ans[i]='o';
            }else if(w[i]=='\''||w[i]=='"'){
                ans[i]='l';
            }else if(w[i]==']'||w[i]=='}'){
                ans[i]='p';
            }else if(w[i]=='|'||w[i]=='\\'){
                ans[i]='[';
            }else{
                ans[i]=w[i];
            }
        }
        int ln=strlen(w);
        ans[ln]='\0';
        printf("%s\n",ans);
    }
}


