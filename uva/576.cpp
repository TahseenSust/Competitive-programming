#include<bits/stdc++.h>
using namespace std;

bool isvowel(char ch)
{
    if(ch=='a') return true;
    if(ch=='e') return true;
    if(ch=='i') return true;
    if(ch=='o') return true;
    if(ch=='u') return true;
    if(ch=='y') return true;
    return false;
}


int main()
{
    string str;

    while(getline(cin,str)){
        if(str=="e/o/i") return 0;
        str=str+"/";
        int line=1,v=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='/'){
                if(line==1 && v!=5){
                    break;
                }else if(line==2 && v!=7){
                    break;
                }else if(line==3 && v!=5){
                    break;
                }else if(line>3){
                    line=0;
                    break;
                }
                line++;
                v=0;
            }else{
                if(isvowel(str[i])){
                    v++;
                    while(isvowel(str[i])) i++;
                    i--;
                }
            }
        }
        if(line==4){
            printf("Y\n");
        }else{
            cout<<line<<endl;
        }
    }
}
