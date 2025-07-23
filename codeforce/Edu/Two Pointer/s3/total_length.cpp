#include <bits/stdc++.h>
using namespace std;
#define all(v)        v.begin(), v.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             int64_t
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define p(x)            cout << (x) << endl;
#define sp(x)           cout << (x) << " ";
#define endl            '\n'
#define pb              push_back
#define mxv(v)        *max_element(v.begin(), v.end())
#define mnv(v)        *min_element(v.begin(), v.end())
#define smv(v)        accumulate(v.begin(), v.end(), 0LL)
#define srt(v)        sort(v.begin(), v.end())
#define rev(v)        reverse(all(v))
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int sunTillN(int n){
    return (n)*(n+1)/2;
}


signed main(){
    int n,s; 
    cin >> n >> s;
    vi v(n); l(i,0,n) cin >> v[i];

    int p1 = 0, p2 = 0;
    int ans = 0;
    int sum = 0;

    while( p2 < n){

        // inserting one at a time and seeing how many first_pointer will reach out till pointer_two
        sum += v[p2];
        p2++;

        while( sum > s){
            sum -= v[p1];
            p1++;
        }

        ans += sunTillN(p2-p1);
        
    }
    cout << ans << endl;
    return 0;
}