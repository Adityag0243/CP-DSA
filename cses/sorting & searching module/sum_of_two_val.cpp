#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define vpi             vector<pair<int,int>>
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
    int t = 1;
    
    while(t--){
        int n,x;
        cin >> n >> x;
        vpi v(n);
        l(i,0,n){
            cin >> v[i].first;
            v[i].second = i+1;
        }
        srt(v);
        int pt1 = 0;
        int pt2 = n-1;

        while(pt1 < pt2){
            if(v[pt1].first + v[pt2].first == x){
                cout<< v[pt1].second << " "<<v[pt2].second;
                return 0;
            }
            else if(v[pt1].first + v[pt2].first > x){
                pt2--;
            }else{
                pt1++;
            }
        }
        cout<<"IMPOSSIBLE";
        
    }
}