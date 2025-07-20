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

int fn(int i, int j, int k){
    if(i < 0 || i >= k || j <0 || j >= k) return 0;

    int cnt = 0;
    if( i-1 >= 0 && j-2 >= 0) cnt++;
    if( i+1 < k  && j-2 >= 0) cnt++;

    if( i-1 >= 0 && j+2 < k) cnt++;
    if( i+1 < k  && j-2 >= 0) cnt++;

    if( i+2 < k && j-1 >= 0) cnt++;
    if( i+2 < k && j+1 < k) cnt++;

    if( i-2 >= 0 && j-1 >= 0) cnt++;
    if( i-2 >=0  && j+1 < k) cnt++;

    return k*k - cnt - 1;    
}

signed main(){
    int n; cin >> n;
    vi v(n+5);

    v[2] = 12;
    v[3] = 28*2;
    v[4] = 96*2;
    for(int k = 5; k <= n ; k++){

        int cnt1 = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cnt1 += (fn(i,j,k));
            }
        }
        cnt1 *= 2;  
        cnt1 += fn(0,2,k)*(k-4);
        cnt1 += fn(1,2,k)*(k-4);

        cnt1 *= 2; 

        int cnt2 = 0;
        cnt2 += fn(2,0,k) * (k-4);
        cnt2 += fn(2,1,k) * (k-4);
        cnt2 *= 2;

        v[k] = cnt1 + cnt2 ;
        if(k > 4) v[k] += (k*k - 9) * (k-4)*(k-4);

    }

    int minus = 10;
    for(int i = 1; i<=n ; i++){
        if(i <= 4) minus = 0;
        else minus = 10 + (i-5)*2;
        cout << v[i]/2 - minus << endl;
    }
    return 0;
}