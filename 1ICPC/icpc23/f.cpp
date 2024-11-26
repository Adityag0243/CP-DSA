#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define l(i, st, n) for (int i = st; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int fn(vi &v1, vi &v2, int i, int max1, int max2, vector<vector<vector<int>>>& memo) {
    if (i >= v1.size()) return 0; 

    if (memo[i][max1][max2] != -1) {
        return memo[i][max1][max2]; 
    }

    int result = 0;

    if (max(v1[i], v2[i]) <= max1 + max2) {
        vector<int> v = {max1, max2, max(v1[i], v2[i])};
        sort(v.begin(), v.end());
        result = 1 + fn(v1, v2, i + 1, v[1], v[2], memo);
    }

    else if (min(v1[i], v2[i]) <= max1 + max2) {
        vector<int> v = {max1, max2};
        sort(v.begin(), v.end());
        result = max(1 + fn(v1, v2, i + 1, v[1], max(v[0], min(v1[i], v2[i])), memo),
                     fn(v1, v2, i + 1, v[1], max(v[0], max(v1[i], v2[i])), memo));
    } 

    else {
        result = fn(v1, v2, i + 1, max1, max2, memo);
    }

    memo[i][max1][max2] = result; 
    return result;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v1(n), v2(n);
        l(i, 0, n) cin >> v1[i];
        l(i, 0, n) cin >> v2[i];


        int max_value = max(*max_element(v1.begin(), v1.end()), *max_element(v2.begin(), v2.end())) + 1;
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(max_value, vector<int>(max_value, -1)));

        cout << fn(v1, v2, 2, max(v1[0], v2[0]), max(v2[1], v1[1]), memo) << endl;
    }
}
