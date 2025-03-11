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
#define printv(i,v)     for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
    int t = 1;
  
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        vi a(n);
        l(i,0,n) cin >> a[i];

        vi b(m);
        l(i,0,m) cin >> b[i];

        // l(i,0,n) cout << a[i]<< " ";

        for(int i = 1; i < n; i++){
            if(a[i] != 0) a[i] += a[i-1];
        }
        for(int i = 1; i < m; i++){
            if(b[i] != 0) b[i] += b[i-1];
        }

        // l(i,0,n) cout << a[i]<< " ";

        vi afreq(n+1,0);
        vi bfreq(m+1,0);

        l(i,0,n){
            afreq[a[i]]++;
        }
        l(i,0,m){
            bfreq[b[i]]++;
        }

        // reverse loop to get sufix sum let say ===> afreq[3] = 7 means i can get continuous 3 in 7 diff ways from array a
        rl(i,1,n){
            afreq[i] += afreq[i+1];
        }
        rl(i,1,m){
            bfreq[i] += bfreq[i+1];
        }

        // l(i,0,n) cout << a[i] << " ";
        // printv(i,afreq);
        // cout << endl;
        // printv(i,bfreq);
        // cout << endl;

        int ans = 0;
        for(int i = 1; i*i <= k ; i++){
            if(k % i == 0){
                if(i <= n && k/i <=m )  ans += (afreq[i] * bfreq[k/i]);
                if(i <= m && k/i <=n && i != k/i)  ans += (afreq[k/i] * bfreq[i]);
            }
        }

        cout << ans ;

       

        
    }
}