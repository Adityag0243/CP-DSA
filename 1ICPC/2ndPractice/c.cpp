#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             int64_t
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define p(x)            cout << (x) << endl;
#define sp(x)           cout << (x) << " ";
#define endl            '\n'
#define pb              push_back
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


vector<int> patternDecimals;

// Function to generate pattern and convert to decimal, storing in the global vector
void generatePatternAndConvert(int length) {
    for (int group_size = 1; group_size <= length; group_size++) {
        if()
        string pattern;
        int i = 0;
        
        while (pattern.size() < length) {
            char bit = (i % 2 == 0) ? '1' : '0';
            pattern += string(group_size, bit);
            i++;
        }

        pattern = pattern.substr(0, length);

        // Convert binary string to decimal and push into global vector
        int decimal_value = bitset<12>(pattern).to_ulong();
        patternDecimals.push_back(decimal_value);
    }
}



signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n);
        l(i,0,n) cin >> v[i];
        
    }
}