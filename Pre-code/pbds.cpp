//find_by_order() - returns an iterator to the k-th largest element (counting from zero)

//order_of_key() - the number of items in a set that are strictly smaller than our item

/*
me.insert({x, t++});
me.erase(me.lower_bound({x, 0}));
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost; // set

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset; // multiset

int main()
{
    ost X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(5))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
    X.erase(16);
    cout<<X.order_of_key(400)<<endl<<endl;


    // Multiset - (erase doesn't work)
    indexed_multiset Y;

    Y.insert(1);
    Y.insert(1);
    Y.insert(2);
    Y.insert(2);
    Y.insert(3);
    Y.insert(3);

    cout<<*Y.find_by_order(0)<<endl; // 1
    cout<<*Y.find_by_order(1)<<endl; // 1
    cout<<*Y.find_by_order(2)<<endl; // 2
    cout<<*Y.find_by_order(3)<<endl; // 2
    cout<<*Y.find_by_order(4)<<endl; // 3
    cout<<*Y.find_by_order(5)<<endl; // 3
    cout<<(end(Y)==Y.find_by_order(6))<<endl<<endl; // true

    cout<<Y.order_of_key(-5)<<endl; // 0
    cout<<Y.order_of_key(1)<<endl; // 0
    cout<<Y.order_of_key(2)<<endl; // 2
    cout<<Y.order_of_key(3)<<endl; // 4
    cout<<Y.order_of_key(4)<<endl; // 6

    return 0;
}
