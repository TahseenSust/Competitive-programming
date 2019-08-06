#include<bits/stdc++.h>
using namespace std;

string to_str(int n)
{
    string str="";
    while(n){
        str+=((n%10)+'0');
        n/=10;
    }
    reverse(str.begin(),str.end());
    return str;
}
int main()
{
    int n;
    while(cin>>n){
//        if(n==8){
//            cout<<"00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n";
//            continue;
//        }
        int num1=0,num2=0,nine=0;
        for(int i=1;i<=n;i++){
            nine=nine*10+9;
        }
        //cout<<nine<<endl;
        for(int i=0;i*i<=nine;i++){
            string str=to_str(i*i);
            if(str.size()<n){
                string tmp="";
                for(int j=0;j<n-str.size();j++){
                    tmp+="0";
                }
                str=tmp+str;
            }
            num1=num2=0;
            for(int j=0;j<n/2;j++){
                num1=num1*10+(str[j]-'0');
            }
            for(int j=n/2;j<n;j++){
                num2=num2*10+(str[j]-'0');
            }
            if((num1+num2)*(num1+num2)==i*i){
                cout<<str<<endl;
            }
        }
    }

}
