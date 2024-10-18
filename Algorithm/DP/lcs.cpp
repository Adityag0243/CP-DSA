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
    string s,t;
    cin >> s;
    cin >> t;
    int dp[s.length()+1][t.length()+1];

    l(i,0,s.length()+1){
        dp[i][0] = 0;
    }
    l(i,0,t.length()+1){
        dp[0][i] = 0;
    }

    l(i,0,s.length()){
        l(j,0,t.length()){
            dp[i+1][j+1] = max(dp[i][j+1] , dp[i+1][j]);

            if(s[i] == t[j]){
                dp[i+1][j+1] = max(dp[i+1][j+1] , dp[i][j] + 1);
            }
        }
    }

    // l(i,0,s.length()+1){
    //     l(j,0,t.length()+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    string st = "";

    int cnt = dp[s.length()][t.length()];
    int till = t.length()+1;


    rl(i,1,s.length()+1){
        rl(j,1,till){
            // cout << cnt<<" ";
            
            if(dp[i][j] != cnt) break;
            if(s[i-1]==t[j-1]){
                cnt--;
                till = j;
                st += s[i-1];
                break; 
            }
        }
    }
    reverse(st.begin(), st.end());
    cout << st <<endl;
}



