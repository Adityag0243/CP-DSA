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
    int t;
    cin >> t;
    vector<int> v(31,0);

    while(t--){
    
    
        int x,y;
        cin >> x >> y;
        if(x == 1){
            v[y]++;
        }
        else{
            vector<int> v2(31,0);
            rl(i,0,30){
                if( y & (1 << i)) v2[i]++;
            }
            bool flag = true;
            l(i,0,30){
                v2[i] -= v[i];
                if(v2[i] > 0){
                    flag = false;
                    break;
                }else{
                    v2[i+1] -= abs(v2[i])/2;
                }
            }
            if(flag) yes
            else no
        }

    }
}