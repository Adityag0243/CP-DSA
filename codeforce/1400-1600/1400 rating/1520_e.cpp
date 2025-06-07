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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        // cout<<"hmmji2 ";
        
        int st=n+1,end=0;
        l(i,0,n){
            if(s[i] == '*'){
                st  = min(st,i);
                end = max(end,i);
            }
        }

        deque<int> space;
        l(i,st,end){
            if(s[i]=='.') space.pb(i);
        }

        int pt1 = st;
        int pt2 = end;
        
        int ans = 0;
        // cout<<"hmm ";
        while(pt1 < pt2 && !space.empty()){
            // cout<<"ok ";
            if( space.front() - pt1  <  pt2 - space.back()){
                ans += space.front() - pt1;
                space.pop_front();
                pt1++;
            }else{
                ans += pt2 - space.back();
                space.pop_back();
                pt2--;
            }
            // cout<<ans<<" ..  ";
        }
        cout << ans << endl;   
    }
}