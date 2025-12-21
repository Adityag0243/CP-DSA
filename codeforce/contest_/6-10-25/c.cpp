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
        int n; cin >> n;
        string s; cin >> s;
        vi as, bs;
        map<int,int> mp;

        int i = 0;
    
        while( i < n){
            int j = i, cnt = 0;
            while( j < n && s[j] == s[i]){
                cnt++;
                j++;
            }
            if( s[i] == 'a'){
                mp[cnt]++;
                as.pb(cnt);
            }
            else{
                mp[cnt]--;
                bs.pb(cnt);
            }
            i = j;
        }

        
    

        if( as.size() == 0 || bs.size() == 0){
            cout << -1 << endl;
            continue;
        }

        int cnta = smv(as);
        int cntb = smv(bs);

        if( cnta == cntb ){
            cout << 0 << endl;
            continue;
        }



        vi dp(n+1, 0);
        dp[0] = 1;
        srt(as);
        srt(bs);

        for( int c : as ){
            for( int i = n; i >= 1; i--){
                if( i - c >= 0 && dp[i-c] == 1) dp[i] = 1;
            }
        }

        vi dp2(n+1, 0);
        dp2[0] = 1;

        for( int c : bs ){
            for( int i = n; i >= 1; i--){
                if( i - c >= 0 && dp2[i-c] == 1) dp2[i] = 1;
            }
        }

        int ans = 0;
        l(i,1,n+1) if(dp[i] == 1 && dp[i] == dp2[i]) ans = i;

        if( ans == 0 ) cout << -1 << endl;
        else{
            cout << n - 2*ans << endl;
        }
       
    }
    return 0;
}