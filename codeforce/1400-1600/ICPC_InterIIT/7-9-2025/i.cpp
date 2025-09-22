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

bool check(vi &v){
    bool flag = true;
    int n = v.size();
    l(i,1,n) if( v[i] < v[i-1]) flag = false;
    return flag;
}

signed main(){
    int n; cin >> n;
    vi v(n+2); l(i,1,1+n) cin >> v[i];
    v[n+1] = INT_MAX;
    int pMaxi = n;

    l(i,1,n+1){
        if(v[i] > v[i-1] ){
            pMaxi = i;
        }else{
            break;
        }
    }

    if(pMaxi == n){
        bool flag = true;
        l(i,1,1+n) if( v[i] < v[i-1]) flag = false;
        if(flag)cout << n << " " << n;
        else cout << "impossible";
    }else{
        int pMini = pMaxi;
        l(i,pMaxi+1, n+1){
            if( v[i-1] >= v[i]){
                pMini = i;
            }else{
                break;
            }
        }

        if(pMini == n){
                reverse(v.begin() + pMaxi, v.begin() + pMini + 1);
                bool flag = check(v);
                if(flag) cout << pMaxi << " " << pMini ;
                else cout << "impossible";
            // }
        }else{
            // if(v[pMini] < v[pMaxi - 1] || v[pMaxi] > v[pMini+1]  ) cout << "impossible";
            // else{
                bool find = false;
                l(i, pMini+1, n+1) if(v[i] < v[i-1]) find = true;
                
                if(find) cout << "impossible";
                else{
                    reverse(v.begin() + pMaxi, v.begin() + pMini + 1);
                    bool flag = check(v);
                    if(flag) cout << pMaxi << " " << pMini ;
                    else cout << "impossible";
                }
            // }
        }
    }

    return 0;
}