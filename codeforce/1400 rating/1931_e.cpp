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
    fastio
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >>m;

        int tlen = 0;  // total len of each number expect end zero
        vi len0;
        l(i,0,n){
            string s;
            cin>>s;
            int cnt = 0;
            rl(j,0,s.size()){
                if(s[j] != '0') break;
                cnt++;
            }
            len0.pb(cnt);
            tlen += (s.size() - cnt);
        }
        sort(len0.rbegin(),len0.rend());    // reverse sort
        // anna try to destroy max zero and shasha try to save by combining in someone else in that number
        
        for(int i = 1; i<len0.size() ; i+=2){
            tlen += len0[i];
        }

        if(tlen >= m+1) cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;



        
    }
}