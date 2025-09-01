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
        int lens = 1,lent = 1;
        // map<int,int> mps;
        // map<int,int> mpt;

        // mps[(int)'a']++;
        // mpt[-1*(int)'a']++;
        char ssmall = 'a';
        char slarge = 'a';
        char tlarge = 'a';

        l(i,0,n){
            int type, k;
            string s; 
            cin >> type >> k >> s;
            
            for(char &c : s){
                if(type == 1){
                    // mps[(int)c]+=k;
                    ssmall = min(ssmall, c);
                    slarge = max(slarge, c);
                    lens += k;
                }else{
                    // mpt[-1* (int)c] += k;
                    tlarge = max(tlarge, c);
                    lent += k;
                }
            }
            if( tlarge > ssmall ) yes
            else{
                if(lent > lens && slarge == tlarge) yes
                else no
            }
        }
    }
    return 0;
}