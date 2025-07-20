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
#define smv(arr)        accunumate(arr.begin(), arr.end(), 0LL)
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
        int n,m; cin >> n >> m;

        int val = n;
        int x = 0;
        while(val % 2 == 0){
            x++;
            val /= 2;
        }

        val = n;
        int y = 0;
        while( val % 5 == 0){
            y++;
            val /= 5;
        }

        if( x >= y){

            int dif = x - y;
            int num = 1;
            int j = 0;
            int prev = num;

            while( num <= m){
                prev = num;
                num *= 5;
                if( j >= dif) num *= 2;

                j++;
            }
            num = prev;
            
            //  I got num with at max zeroes 
            num = (m/num) * num;
            cout << num * n << endl;
        }else{

            int dif = y - x;
            int num = 1;
            int j = 0;
            int prev = num;

            while( num <= m){
                prev = num;
                num *= 2;
                if(j >= dif) num *= 5;
                j++;
            }
            num = prev;
            //  I got num with at max zeroes 
            num = (m/num) * num;
            cout << num * n << endl;

        }
        
    }
    return 0;
}