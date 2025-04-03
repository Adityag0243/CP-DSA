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

void printBinary(int n) {
    if (n > 1) 
        printBinary(n / 2); // Recursive call to process higher bits

    cout << (n % 2); // Print the last bit
}



signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
   
        // I need to find such k so that after adding in both x and y 
        // x += k , y += k
        // let say    x > y 
        // let say   l = 2^something         greater that x and y both

        // Now k = l - max(x,y)  
        //  max_value + k  == l    which has only 1 bit on
        //  min_value + k   < l      now taking xor and and will be same  that is l + (max_value + k)...


        if(x == y) cout << -1 << endl;
        else cout << (1ll << 31) - max(x,y) << endl;

    }
    return 0;
}
