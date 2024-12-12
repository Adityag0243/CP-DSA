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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vi ans(n,0);
        int K = k;
        
        l(i,0,n){
            if(k == 0) break;
            if( (K&1) && s[i]=='1'){
                ans[i] =1;
                k--;
            }else if( (K&1)==0 && s[i]=='0'){
                ans[i]=1;
                k--;
            }
        }
        ans[n-1] += k;

        l(i,0,n){
            if((K - ans[i])&1){
                if(s[i] == '1') s[i] = '0';
                else s[i] = '1';
            }
        }
                
        cout<<s<<endl;
        l(i,0,n) cout<<ans[i]<<" ";
        cout<<endl;
        
    }
}