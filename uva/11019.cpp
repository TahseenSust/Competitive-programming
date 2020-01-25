#include<bits/stdc++.h>
using namespace std;

string text[1002],pattern[102];
int lps[102][102],mat[1002][1002];
int n,m,x,y;

void build_lps(string p,int id)
{
    int sz = p.size();
    memset(lps[id],0,sizeof lps[id]);
    int j = 0;
    lps[id][0] = 0;
    for(int i = 1; i < sz; i++)
    {
        while(j >= 0 && p[i] != p[j])
        {
            if(j >= 1)
                j = lps[id][j - 1];
            else
                j = -1;
        }
        j++;
        lps[id][i] = j;
    }
}
int ans;
///returns matches in vector ans in 0-indexed
int kmp(string s, string p,int id)
{
    int ret=0;
    int psz = p.size(), sz = s.size();
    int j = 0;
    for(int i = 0; i < sz; i++)
    {
        while(j >= 0 && p[j] != s[i])
            if(j >= 1)
                j = lps[id][j - 1];
            else
                j = -1;
        j++;
        if(j == psz)
        {
            j = lps[id][j - 1];
            if(mat[id-1][i]){
                mat[id][i]=1;
                if(id==x){
                    ret++;
                }
            }
        }
        ///after each loop we have j=longest common suffix of s[0..i] which is also prefix of p
    }
    return ret;
}

int search_p(int indx)
{
    int ret=0;
    memset(mat,0,sizeof mat);
    memset(mat[0],1,sizeof mat[0]);
    for(int i=1;i<=x && indx+i-1<=n;i++){
        ret+=kmp(text[indx+i-1],pattern[i],i);
    }
    return ret;
}
int main()
{
    int t;

    cin>>t;

    while(t--){

        cin>>n>>m;

        for(int i=1;i<=n;i++){
            cin>>text[i];
        }
        cin>>x>>y;

        for(int i=1;i<=x;i++){
            cin>>pattern[i];
            build_lps(pattern[i],i);
        }
        int re=0;
        for(int i=1;i<=n;i++){
            re+=search_p(i);
        }

        cout<<re<<endl;
    }
}
