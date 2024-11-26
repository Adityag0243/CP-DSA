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
   
    
    int n;
    cin >> n;
    vi v(n);
    l(i,0,n) cin >> v[i];
    int ans = v[0];
    l(i,1,n){
        ans = __gcd(ans,v[i]);
    }
    if(ans > 1){
        yes
        cout<<0<<endl;

        return 0;
    }
    int cnt = 0; 

    // any number   a , b   i can make it's gcd 2 after 2 operation for sure --> a, b after 2 operation -2b , 2a 
    // if both are odd then I can make in 1 operation   {odd , odd}  after 1 operation --> {odd-odd , odd+odd}
    
    l(i,0,n-1){
        if((v[i]&1) == 0) continue;
        else if( v[i+1]&1 ){
            cnt++;     
            v[i]++;
            v[i+1]++;
        }
    }
    l(i,0,n) if(v[i]&1) cnt+=2;
    yes
    cout<<cnt<<endl;
}