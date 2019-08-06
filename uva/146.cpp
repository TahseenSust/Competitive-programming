#include<bits/stdc++.h>
using namespace std;
int main()
{
    char code[100];
    while(gets(code)){
        if(strcmp(code,"#")==0){
            break;
        }
        int ln,cnt=0;
        ln=strlen(code);
        do{
            cnt++;
            if(cnt>=2){
                cout<<code<<endl;
                break;
            }
        }while(next_permutation(code,code+ln));
        if(cnt==1){
            cout<<"No Successor\n";
        }
    }
}
