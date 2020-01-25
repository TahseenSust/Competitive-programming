#include<bits/stdc++.h>
using namespace std;

vector<int> build_lps(string p)
{
    int sz = p.size();
    vector<int> lps;
    lps.assign(sz + 1, 0);
    int j = 0;
    lps[0] = 0;
    for(int i = 1; i < sz; i++)
    {
        while(j >= 0 && p[i] != p[j])
        {
            if(j >= 1)
                j = lps[j - 1];
            else
                j = -1;
        }
        j++;
        lps[i] = j;
    }
    return lps;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str,tmp;
    int t;

    cin>>t;

    while(t--){
        cin>>str;

        tmp=str;
        reverse(tmp.begin(),tmp.end());

        str=str+"#"+tmp;

        vector<int>lps=build_lps(str);

        int mx=0;

        for(int i=tmp.size();i<lps.size();i++){
            mx=max(mx,lps[i]);
        }

        string ans;

        for(int i=0;i<mx && i<tmp.size();i++){
            ans+=str[i];
        }
        reverse(ans.begin(),ans.end());

        cout<<ans<<endl;
    }


}
