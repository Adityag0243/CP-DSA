#include<bits/stdc++.h>
using namespace std;

// #define int int64_t

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



signed main(){
    int n,k; cin >> n >> k;
    k++;
    ordered_set os;
    for(int i = 1; i <= n; i++) os.insert(i);

    int pos = 0;

    while( os.size() > 0 ){
        pos += (k - 1);
        pos = pos % os.size();

        int val = *(os.find_by_order(pos));
        cout << val << " "; 
        os.erase(val);        
    }

}