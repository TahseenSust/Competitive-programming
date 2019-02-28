#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

int main()
{
    int n,k;

    cin>>n>>k;

    ost st;

    for(int i=1;i<=n;i++){
        st.insert(i);
    }

    int sz=n,indx=k;

    while(sz>1){
        int num=*st.find_by_order(indx-1);
        cout<<num<<' ';
        st.erase(num);
        sz--;
        indx=(indx+k-1)%sz;

        if(indx==0) indx=sz;

    }
    cout<<*st.find_by_order(0)<<endl;
}

