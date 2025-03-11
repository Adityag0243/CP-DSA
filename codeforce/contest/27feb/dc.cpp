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

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,x,k;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        vi v(n,0);

        l(i,0,n){
            if(s[i] == 'R') v[i]++;
            else v[i]--;
        }  

        l(i,1,n)
        {
            v[i] += v[i-1];
        }

        int second = n+1;  // assuming landing zero at n+1

        l(i,0,n){
            if( v[i] + x == 0){
                second = i+1;
                break;
            }
        }

        if(second > k || second > n )   cout << 0 << endl;
        else
        {
            int first_zero = -1;

            l(i,0,n) 
                if(v[i] == 0){
                    first_zero = i+1;
                    break;
                }

            k -= second;  // seconds remains

            if(first_zero == -1) k = 0;   // if we never going to get zero after restart then answer is 1 always

            cout << 1 + k / (first_zero) << endl; 
        }

    }
}