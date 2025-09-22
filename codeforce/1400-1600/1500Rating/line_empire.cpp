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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,a,b; cin >> n >> a >> b;
        vi v(n+1); l(i,1,1+n) cin >> v[i];

        int cost = 0;

        if( a <= b){
            l(i,1,n+1){
                cost += (v[i] - v[i-1]) * b;
                if(i != n) cost += (v[i] - v[i-1]) * a;
            }
        }else{
            int aPoint = 0;
            
            l(i,1,n+1){
                if( (n-i)*(v[i])*b - v[i]*a  > 0){
                    aPoint = i;
                }
            }

            cost += (v[aPoint] * a);
            l(i,1,1+n){

                if(i <= aPoint){
                    cost += (v[i] - v[i-1]) * b; 
                }else{
                    cost += (v[i] - v[aPoint]) * b;
                }
            }

        }
        cout << cost << endl;
    }
    return 0;
}