#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
// #define int             int64_t
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

string fn(vi &a, vi &b, int bit){
    string ans = "Tie";
    int n = a.size();


    int xa = 0, xb = 0;
    l(i,0,n){
        xa ^= ((a[i] >> bit) & 1);
        xb ^= ((b[i] >> bit) & 1);
    }

    int last = -1;
    rl(i,0,n){
        if( ((a[i] >> bit) & 1)!=( (b[i] >> bit) & 1)){
            if(last == -1) last = i;
        } 
        if(last != -1) break;
    }

    if( last != -1 ){
        if( xa == xb ){

        }
        else if( last & 1 ){
            ans = "Mai";
        }else{
            ans = "Ajisai";
        }
    }

    return ans;
}



int main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n); for( int &i : a) cin >> i;
        vi b(n); for( int &i : b) cin >> i;

        
        
        string ans = "Tie";
        for(int bit = 30; bit >= 0; bit--){
            ans = fn(a,b,bit);
            if( ans != "Tie") break;
        }

        cout << ans << endl;
    }
    return 0;
}