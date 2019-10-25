//Lyndon factorization

#include<bits/stdc++.h>
using namespace std;

int min_cyclic_string(string s) {
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return ans+1;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        string str;

        cin>>str;

        cout<<min_cyclic_string(str)<<endl;
    }

}
