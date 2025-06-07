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
    int n,k1,k2;
    cin >> n >> k1 >> k2;

    vi a(n);
    l(i,0,n) cin >> a[i];
    vi b(n);
    l(i,0,n) cin >> b[i];

    priority_queue< pair<int,int> > pq;
    l(i,0,n){
        pq.push({abs(a[i]-b[i]),i});
    }

    while(k1--){
        int diff = pq.top().x;
        int ind = pq.top().y;
        pq.pop();
        if( abs( a[ind]+1 - b[ind] )  <= diff){
            a[ind]++;
        }else{
            a[ind]--;
        }
        pq.push({abs(a[ind]-b[ind]),ind});
    }

    while(k2--){
        int diff = pq.top().x;
        int ind = pq.top().y;
        pq.pop();
        if( abs( b[ind]+1 - a[ind] )  <= diff){
            b[ind]++;
        }else{
            b[ind]--;
        }
        pq.push({abs(a[ind]-b[ind]),ind});
    }

    int ans = 0;
    l(i,0,n) ans += 1ll * ((a[i] - b[i]) * (a[i] - b[i]));
    cout << ans << endl;


    return 0;
}