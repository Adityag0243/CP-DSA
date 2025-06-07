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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vi a(n);
        l(i,0,n) cin >> a[i];

        vi b(m);
        l(i,0,m) cin >> b[i];

        int ans = 2e9;

        int prev_ind = m-1;
        int j = m-1;
        rl(i,0,n){
            if( j < 0) break;
            if( a[i] >= b[j]){
                j--;
                prev_ind = j;
            }
        }

        if(prev_ind == -1){
            cout << 0 << endl;
        }else{
            int ans = -1;
            j = m-1;
            rl(i,0,n){
                if(j < 0) break;
                if( j == prev_ind){
                    ans = b[j];
                    i++;
                    j--;
                }else if( a[i] >= b[j]){
                    j--;
                }
            }

            if( j == 0){
                if(ans == -1){
                    ans = b[0];
                    j--;
                }
            }
            if(j >= 0 || ans == 2e9) ans = -1;
 
            if(ans == -1) cout << ans << endl;
            else{
                prev_ind = 0;

                j = 0;
                l(i,0,n){
                    if( j >= m) break;
                    if( a[i] >= b[j]){
                        j++;
                        prev_ind = j;
                    }
                }

                if(prev_ind == m){
                    cout << 0 << endl;
                }else{

                    j = 0;
                    int ans2 = 2e9;
                    // cout << prev_ind << "prev\n";
                    l(i,0,n){
                        if( j >= m) break;
                        if( j == prev_ind){
                            ans2 = b[j];
                            j++;
                            i--;
                        }
                        else if( a[i] >= b[j]){
                            j++;
                        }
                    }

                    // cout << "her: "<< ans2 <<"  ";

                    if( j == m-1){
                        if(ans2 == 2e9){
                            ans2 = b[m-1];
                            j++;
                        }
                    }

                    if(j >= m){
                        ans = min(ans,ans2);
                    }

                    cout << ans << endl;

                }




            }
            
        }
        

    }
    return 0;
}