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
    
        int n,m,k;
        cin >> n >> m >> k;
        vi a(n);
        l(i,0,n) cin >> a[i];
        vector<pair<int,int>> b(m);
        l(i,0,m){
            int bi;
            cin>>bi;
            b[i] = { bi-k, bi+k };
        }
        srt(a);
        srt(b);
        // l(i,0,n) cout<<a[i]<<" ";
        // cout<<endl;
        // l(i,0,m) cout<<b[i].first<<" "<<b[i].second<<",   ";
        // cout<<endl;

        // cout<<"idhar hu ";

        int j = 0;
        int i = 0;
        int cnt = 0;

            while(j < m && i<n){
                // cout<<"heere "<<i <<j<<"  ";
                if(a[i] >= b[j].first && a[i] <= b[j].second){
                    cnt++;
                    i++;
                }else if(a[i] < b[j].first){
                    i++;
                    j--;
                }
                j++;
            }
        cout<<cnt;

        
}
