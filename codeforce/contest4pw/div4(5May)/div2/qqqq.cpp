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
        int n ;
        cin >>n;
        char a[2][n];
        int cnt[n];
        l(i,0,n) cnt[i] = 0;
        l(i,0,2){
            l(j,0,n){
                cin>>a[i][j];
                if(a[i][j] == 'A') cnt[j]++;
            }
        }
        // l(i,0,n) cout <<cnt[i]<<" ";
        // cout<<endl;

        int ans = 0;
        for(int i=0 ; i<n ; i+=3){
            int c = cnt[i]+cnt[i+1]+cnt[i+2];
            if( c >= 4 ) ans+=2;
            else if( c>= 2) ans+=1; 
        }
        cout <<ans<<endl;
        
       
    }
}