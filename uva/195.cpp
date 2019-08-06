#include<bits/stdc++.h>
using namespace std;

bool cmp(char a,char b)
{
    int aa,bb;
    if(isupper(a)){
        aa=(a-'A')*2;
    }else{
        aa=(a-'a')*2+1;
    }
    if(isupper(b)){
        bb=(b-'A')*2;
    }else{
        bb=(b-'a')*2+1;
    }
    return aa<bb;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        sort(str.begin(),str.end(),cmp);
        do
        {
            cout<<str<<endl;
        }
        while(next_permutation(str.begin(),str.end(),cmp));
    }

}
