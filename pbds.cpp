#include"bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
int main(){
    pbds A;
    A.insert(4);
    A.insert(0);
    A.insert(2);
    A.insert(1);
    cout<<"A's Value \n";
    for(auto &i:A)cout<<i<<" ";
    cout<<'\n';
    cout<<"Access via index\n";
    cout<<"0th Element "<<*A.find_by_order(0)<<'\n';
    cout<<"1st Element "<<*A.find_by_order(1)<<'\n';
    cout<<"2nd Element "<<*A.find_by_order(2)<<'\n';
    cout<<"3rd Element "<<*A.find_by_order(3)<<'\n';
    cout<<"Number of Elements less than 3\n";//TimeComplexity O(logn)
    cout<<A.order_of_key(3)<<'\n';
    cout<<"Number of Elements less than 10\n";//TimeComplexity O(logn)
    cout<<A.order_of_key(10)<<'\n';
    cout<<"Some Binary Search Functions\n LowerBound\n";
    cout<<*A.lower_bound(4)<<'\n';
    cout<<"Some Binary Search Functions\nUpper Bound\n";
    cout<<*A.upper_bound(4)<<'\n';
    A.erase(0);
    A.insert(3);
    A.erase(2);
     cout<<"A's Modified Value \n";
    for(auto &i:A)cout<<i<<" ";


}