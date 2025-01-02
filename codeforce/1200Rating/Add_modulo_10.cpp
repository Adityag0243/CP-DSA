#include<bits/stdc++.h>
using namespace std;

using namespace std;



void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 5 == 0) {
            flag = true;
            a[i] = a[i] + a[i]%10;
        }
    }
    
    
    // // 5 --> 0   (1 step only)
        
    //               7    
    //                 \
    // // 1 -->  2 ---> 4 
    //           \       \
    //             \       8  <-- 9
    //               \   /
    //         3 -->   6  
            
            
    if (flag) {
        cout << (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end()) ? "Yes": "No") << '\n';
    } else {
        bool flag2 = false, flag12 = false;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            while (x % 10 != 4) {
                x = x + x%10;
            }
            if (x % 20 == 4) {
                flag2 = true;
            } else {
                flag12 = true;
            }
        }
        cout << ((flag2 & flag12) ? "No" : "Yes") << '\n';  
        //now everyone has same modulo from (2,4,8,6) then we can jump them 20 many time to converse at one no 
    }
}

int main() {
    int t = 1;
    cin >> t;
    for (int it = 0; it < t; ++it) {
        solve();
    }
    return 0;
}