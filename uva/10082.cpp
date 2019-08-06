#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    //getline(cin,str);
    while(getline(cin,str)){
        string ans="";
        for(int i=0;i<str.size();i++){
            if(str[i]=='1'){
                ans+="`";
            }else if(str[i]=='2'){
                ans+="1";
            }else if(str[i]=='3'){
                ans+="2";
            }else if(str[i]=='4'){
                ans+="3";
            }else if(str[i]=='5'){
                ans+="4";
            }else if(str[i]=='6'){
                ans+="5";
            }else if(str[i]=='7'){
                ans+="6";
            }else if(str[i]=='8'){
                ans+="7";
            }else if(str[i]=='9'){
                ans+="8";
            }else if(str[i]=='0'){
                ans+="9";
            }else if(str[i]=='-'){
                ans+="0";
            }else if(str[i]=='='){
                ans+="-";
            }else if(str[i]=='W'){
                ans+="Q";
            }else if(str[i]=='E'){ans+="W";}
            else if(str[i]=='R'){ans+="E";}
            else if(str[i]=='T'){ans+="R";}
            else if(str[i]=='Y'){ans+="T";}
            else if(str[i]=='U'){ans+="Y";}
            else if(str[i]=='I'){ans+="U";}
            else if(str[i]=='O'){ans+="I";}
            else if(str[i]=='P'){ans+="O";}
            else if(str[i]=='['){ans+="P";}
            else if(str[i]==']'){ans+="[";}
            else if(str[i]=='\\'){ans+="]";}
            else if(str[i]=='S'){ans+="A";}
            else if(str[i]=='D'){ans+="S";}
            else if(str[i]=='F'){ans+="D";}
            else if(str[i]=='G'){ans+="F";}
            else if(str[i]=='H'){ans+="G";}
            else if(str[i]=='J'){ans+="H";}
            else if(str[i]=='K'){ans+="J";}
            else if(str[i]=='L'){ans+="K";}
            else if(str[i]==';'){ans+="L";}
            else if(str[i]=='\''){ans+=";";}
            else if(str[i]=='X'){ans+="Z";}
            else if(str[i]=='C'){ans+="X";}
            else if(str[i]=='V'){ans+="C";}
            else if(str[i]=='B'){ans+="V";}
            else if(str[i]=='N'){ans+="B";}
            else if(str[i]=='M'){ans+="N";}
            else if(str[i]==','){ans+="M";}
            else if(str[i]=='.'){ans+=",";}
            else if(str[i]=='/'){ans+=".";}
            else if(str[i]==' '){ans+=" ";}
        }
        cout<<ans<<endl;
    }
}

