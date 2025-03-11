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
    int t = 1;
    // cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> v[n];
        vector<int> vc[n];


        vector<int> rxor(n);
        vector<int> cxor(m);

        l(i,0,n){
            int xor_ = 0;
            l(j,0,m){
                int a;
                cin >> a;
                xor_ ^= a;
                v[i].pb(a);
            }
            rxor[i] = xor_;
        }

        l(i,0,n){
            l(j,0,m){
                int a;
                cin >> a;
                vc[i].pb(a);
            }
        }

        l(j,0,m){
            int xor_ = 0;
            l(i,0,n){
                xor_ ^= v[i][j];
            }
            cxor[j] = xor_;
        }

        bool flag = true;

        l(i,0,n){
            l(j,0,m){
                if(v[i][j] != vc[i][j]){
                    if( rxor[i] != v[i][j] ){
                        rxor[i] = v[i][j];
                        v[i][j] = vc[i][j];
                    }else if(cxor[j] != v[i][j]){
                        cxor[j] = v[i][j];
                        v[i][j] = vc[i][j];
                    }else{
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag) yes
        else no


        
    }
}