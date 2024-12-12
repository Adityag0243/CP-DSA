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
    
    int n,s;
    cin >> n >> s;
    vi v(n);
    l(i,0,n) cin >> v[i];

    vi cv = v;
    
    
    int lo =1;
    int hi = n;   
    int ans = 0;
    int amount = 0;


    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        l(i,0,n) cv[i] = v[i] + (i+1)*mid;
        srt(cv);
        l(i,1,n) cv[i]+=cv[i-1];

        if(cv[mid-1] <= s){
            amount = cv[mid-1];
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        } 
    }
    cout<<ans<<" "<<amount<<endl;

    
}