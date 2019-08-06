#include<bits/stdc++.h>
using namespace std;
bool ck(char w[])
{
    int ln=strlen(w);
    for(int i=0;w[i];i++){
        if(w[i]!=w[ln-1-i]){
            return false;
        }
    }
    return true;
}
bool m_c(char w[])
{
    int ln=strlen(w);
    for(int i=0;w[i];i++){
        if(w[i]=='3'||w[i]=='E'){
            if(w[i]=='3'&&w[ln-1-i]=='E'){
                continue;
            }else if(w[i]=='E'&&w[ln-1-i]=='3'){
                continue;
            }else{
                return false;
            }
        }else if(w[i]=='J'||w[i]=='L'){
            if(w[i]=='J'&&w[ln-1-i]=='L'){
                continue;
            }else if(w[i]=='L'&&w[ln-1-i]=='J'){
                continue;
            }else{
                return false;
            }
        }else if(w[i]=='2'||w[i]=='S'){
            if(w[i]=='2'&&w[ln-1-i]=='S'){
                continue;
            }else if(w[i]=='S'&&w[ln-1-i]=='2'){
                continue;
            }else{
                return false;
            }
        }else if(w[i]=='5'||w[i]=='Z'){
            if(w[i]=='5'&&w[ln-1-i]=='Z'){
                continue;
            }else if(w[i]=='Z'&&w[ln-1-i]=='5'){
                continue;
            }else
                return false;
        }else if(w[i]=='B'||w[i]=='C'||w[i]=='D'||w[i]=='F'||w[i]=='G'||w[i]=='K'||w[i]=='N'||w[i]=='P'||w[i]=='Q'||w[i]=='R'||w[i]=='4'||w[i]=='6'||w[i]=='7'||w[i]=='9'){
            return false;
        }else if(w[i]==w[ln-1-i]){
            continue;
        }else{
            return false;
        }

    }
    return true;
}
int main()
{
    char w[25],s[25];
    bool f=false;
    while(scanf("%s",w)!=EOF){
        bool pal=false,mir=false;
        scanf("%*c");
        int ln=strlen(w);
        for(int i=0;w[i];i++){
            if(w[i]=='0'){
                w[i]='O';
            }
        }
        if(f)
           // cout<<endl;
        f=1;
        pal=ck(w);
        mir=m_c(w);
        //printf("%d %d\n",mir,pal);
        if(!pal and !mir){
            printf("%s -- is not a palindrome.\n",w);
        }else if(pal and mir){
            printf("%s -- is a mirrored palindrome.\n",w);
        }else if(pal){
            printf("%s -- is a regular palindrome.\n",w);
        }else if(mir){
            printf("%s -- is a mirrored string.\n",w);
        }
        cout<<endl;
    }
}
/*
NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA
*/

