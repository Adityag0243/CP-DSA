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
    fastio
    int t;
    cin >> t;
    while(t--){
        int n, m , val;
        cin >> n >> m >> val;
        vi v(n);
        l(i,0,n) cin >> v[i];


        int cnt = 0;
        int sum = 0;
        int i = 0;

        vi clt;

        for(i=0; i <n ;i++){
            sum += v[i];
            if(sum >= val){
                clt.pb(sum);
                sum = 0;
                cnt++;
            }
            if(cnt == m) break;
        }

        int ans = 0;
        for(int j = i+1 ; j<n ; j++) ans += v[j];
        clt.pb(ans);

        sum = 0;
        cnt = 0;
        vi clt2;
        
        for(i = n-1 ; i>=0 ; i--){
            sum += v[i];
            if(sum >= val){
                clt2.pb(sum);
                sum = 0;
                cnt++;
            }
            if(cnt == m) break;
        }

        int ians = 0;
        for(int j = i-1 ; j>=0 ;j--) ians+=v[j];
        clt2.pb(ians);
        if(clt.size() < m+1 && clt2.size() < m+1) cout<<-1<<endl;
        else{
            int ans = 0;
            cnt = 0;
            for(i=0; i <n ;i++){
                sum += v[i];
                if(sum >= val && cnt < m){
                    ans = max(ans ,sum);
                    sum = 0;
                    cnt++;
                }
            }
            ans = max(ans ,sum);
            cout<<ans<<"   ";
            cnt = 0;

            for(i = n-1 ; i>=0 ; i--){
                sum += v[i];
                if(sum >= val && cnt<m){
                    ans = max(ans , sum);
                    sum = 0;
                    cnt++;
                }

            }
            ans = max(ans ,sum);
            cout<<ans<<endl;
        }
    
    }
}