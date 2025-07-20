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

signed main(){
    fastio
    int n; cin >> n;
    int x; cin >> x;
    vi v(n); l(i,0,n) cin >> v[i];

    int n1 = n/2, n2 = n - n1;
    int total1 = 1LL << n1;
    int total2 = 1LL << n2;

    vector<int> sums;
    
    for(int i = 0; i<total1; i++){
        long long sum = 0;
        for(int j = 0; j < n/2; j++){
            if( i & (1 << j)) sum += v[j];
        }
        sums.pb(sum);
    }
    srt(sums);
    int cnt = 0;
    for(int i = 0; i<total2; i++){
        long long sum = 0;
        for(int j = n/2; j < n; j++){
            if( i & (1 << (j-n/2))) sum += v[j];
        }
        int ind2 = upper_bound(all(sums), x-sum) - sums.begin();
        int ind1 = lower_bound(all(sums), x-sum) - sums.begin();
         
        cnt += (ind2 - ind1);
    }
    cout << cnt;
    
    return 0;
}