/*
ID: tahseen1
PROG: transform
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char o[50][50],d[50][50];
int n;
bool is90();
bool is180();
bool is270();
bool isref();
bool iscom();
bool ischange();
void print(char a[][50]);
int main()
{
    #ifndef ONLINE_JUDGE
        ofstream cout ("transform.out");
        ifstream cin ("transform.in");
    #endif // ONLINE_JUDGE
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>o[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>d[i][j];
    }
    if(is90()){
        cout<<"1\n";
    }else if(is180()){
        cout<<"2\n";
    }else if(is270()){
        cout<<"3\n";
    }else if(isref()){
        cout<<"4\n";
    }else if(iscom()){
        cout<<"5\n";
    }else if(ischange()){
        cout<<"6\n";
    }else{
        cout<<"7\n";
    }
}
bool is90()
{
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){if(o[i][j]!=d[j][n-1-i]){return false;}}}return true;
}
void print(char a[][50])
{
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){printf("%c ",a[i][j]);}printf("\n");}
}
bool is180()
{
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)if(o[i][j]!=d[n-i-1][n-1-j])return false;}return true;
}
bool is270()
{
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)if(o[i][j]!=d[n-1-j][i])return false;}return true;
}
bool isref()
{
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)if(o[i][j]!=d[i][n-1-j])return false;}return true;
}
bool ischange()
{
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)if(o[i][j]!=d[i][j])return false;}return true;
}
bool iscom()
{
    char tmp[50][50];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j]=d[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=tmp[i][n-1-j];
        }
    }
    //print(o);
    //print(d);
    if(is90()) return true;
    if(is180()) return true;
    if(is270()) return true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=tmp[i][j];
        }
    }
    return false;
}
