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

vi primes;

void pre(){
    vi num(2e6);
    l(i,1,2e6) num[i] = i;

    for(int i = 2; i<2e6; i++){
        if(num[i] == i){
            for(int j = 2*i; j<2e6; j += i){
                num[j] = i;
            }
        }
    }

    for(int i = 2; i<2e5; i++) if(num[i] == i)primes.pb(i);
   
}

signed main(){
    pre();
    fastio
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        if( k > (n * (n-1))/2 ){
            cout << -1 << endl;
        }else{
          
                int i6 = 0;
                int i2 = 1, i3 = 1, ip = 0;
                bool flag = false;

                for(int i = 1; i<= n; i++){
                    for(int j = 1; j <= n ; j++){
                        if( i + j > n) break;
                        for(int n6 = 0; n6 <= n; n6++){
                            int p = n-i-j-n6;
                            if( p > 17984) continue;

                            int cnt = i * (j+p);
                            cnt += j * p;
                            cnt += p*(p-1)/2;
                            cnt += (p * n6);

                            if(cnt == k ){
                                flag = true;
                                i2 = i;
                                i3 = j;
                                ip = p;
                                i6 = n-i-j-p;
                                break;
                            }
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }

                // cout << flag << " : flag\n";
                // cout << i2 << " " << i3 << " " << ip << " "  << i6 << " \n";
                
                l(i,0,i2) cout << 2 << " ";
                l(i,0,i3) cout << 3 << " ";
                l(i,0,ip) cout << primes[i+2] << " ";
                l(i,0,i6) cout << 6 << " ";
                cout << endl;
                
            
        }

    }
    
    return 0;
}