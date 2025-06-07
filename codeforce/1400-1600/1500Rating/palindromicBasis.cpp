#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             long long
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


bool checkPalindrome(int n) {  // Using long long to avoid overflow issues
    if (n < 0) return false; // Negative numbers aren't palindromes
    
    string s = to_string(n);
    int sz = s.size();
    l(i, 0, sz / 2) {
        if (s[i] != s[sz - 1 - i]) return false;
    }
    return true;
}


signed main(){
    fastio
    int t;
    cin >> t;

    const int MAX_N = 40000+5;
    vi v(MAX_N,0);
    v[0] = 1;
    l(i,1,MAX_N){
        if(checkPalindrome(i) == false) continue;
        l(j,0,MAX_N){
            if( i+j  >= MAX_N) break;
            v[i+j] += v[j];
            v[i+j] %= MOD2;
        }
    }

    while(t--){
        int n;
        cin >> n;
        cout << v[n] << endl;
    }
}