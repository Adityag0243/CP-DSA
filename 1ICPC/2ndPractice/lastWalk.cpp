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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi abc(7); 
        l(i, 0, 7) cin >> abc[i];  

        vi v(n);
        l(i, 0, n) cin >> v[i];

        int time1 = abs(v[abc[1]] - v[abc[0]]) * abc[4];
        int time2 = -1;

        if (abs(v[abc[0]] - v[abc[2]]) * abc[4] <= abc[6]) {
            time2 = abc[6];
            time2 += (abs(v[abc[2]] - v[abc[3]]) * abc[5]);
            time2 += (abs(v[abc[3]] - v[abc[1]]) * abc[4]);
        }

        int time = time1;
        if (time2 != -1) time = min(time, time2);
        
        cout << time << endl;
    }
}