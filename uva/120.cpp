#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    while(getline(cin,str)){
        stringstream ss;
        ss<<str;

        vector<int>num;
        int x;

        while(ss>>x){
            num.push_back(x);
        }
        vector<int>chk(num);
        sort(chk.begin(),chk.end());
        int sz=chk.size()-1;
        vector<int>ans;
        cout<<num[0];
        for(int i=1;i<num.size();i++){
            cout<<' '<<num[i];
        }
        cout<<endl;

        while(!is_sorted(num.begin(),num.end())){
            if(chk[sz]==num[sz]){
                sz--;
            }else{
                int indx=0;
                for(int i=0;i<sz;i++){
                    if(num[i]==chk[sz]){
                        indx=i;
                        break;
                    }
                }
                if(indx!=0){
                    ans.push_back(num.size()-indx);
                }
                ans.push_back(num.size()-sz);
                reverse(num.begin(),num.begin()+indx+1);
                reverse(num.begin(),num.begin()+sz+1);
            }
            //getchar();
        }
        ans.push_back(0);
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<' '<<ans[i];
        }
        cout<<endl;
    }
}
