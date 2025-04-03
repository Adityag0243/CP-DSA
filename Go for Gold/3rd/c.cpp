#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long

signed main() {
    fastio;
    
    int n;
    cin >> n;

    vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];

    int oppositeDim = -1;
    
    for (int i = 0; i < 3; i++) {
        if ((a[i] == 0 && b[i] == n) || (a[i] == n && b[i] == 0)) {
            oppositeDim = i;
        }
    }

    if (oppositeDim != -1) {
        int ans = 0;
        int firstDim = (oppositeDim + 1) % 3;
        int secondDim = (oppositeDim + 2) % 3;

        int option1 = min(a[firstDim], b[firstDim]) * 2 + abs(a[firstDim] - b[firstDim]) + n;
        option1 = min(option1, 4*n - option1)  + abs(a[secondDim] - b[secondDim]);

        int option2 = min(a[secondDim], b[secondDim]) * 2 + abs(a[secondDim] - b[secondDim])  + n;
        option2 = min(option2, 4*n -option2) + abs(a[firstDim] - b[firstDim]);

        ans = min(option1, option2) ;
        cout << ans << endl;
    } else {
        cout << abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2]) << endl;
    }

    return 0;
}
