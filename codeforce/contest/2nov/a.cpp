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
        int n ;
        cin >> n;

        vi frq(n+1,0);

        l(i,0,n){
            int c;
            cin>>c;
            frq[c]++;
        }
        // l(i,0,n+1) cout<<frq[i]<<" ";
        int f1= 0;
        l(i,0,n+1){
            if(frq[i]==1) f1++;
        }
        // cout<<f1<<": f,";
        int alice = 2*((f1+1)/2);    // freq 1 wale aadhe alice ko

        
        int diff = 0;  // tota different c
        l(i,0,n+1){
            if(frq[i] > 1) diff++; 
        }
        // if(f1&1){
        //     alice += diff/2;
        // }else{
        //     alice += (diff+1)/2;
        // }
        cout<< alice+diff <<endl;

        
       
        
        
    }
}