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
        int n;
        cin >> n;
        vi v1(n);
        vi v2(n);
        l(i,0,n) cin >> v1[i];
        l(i,0,n) cin >> v2[i];
        bool check = false;
        int sum = 0;
        l(i,0,n){
            if(v1[i] >= v2[i]){
                sum += v1[i];
                v1[i] = -1*1000000;
            }
            else{
                sum+=v2[i];
                v2[i] = -1*1000000;
                check = true;
            }
        }

        if(check == false){
            sum += mxv(v2); 
        }else{
            sum += max(mxv(v2),mxv(v1));
        }
        
        
        cout<<sum<<endl;
        
    }
}