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
    map<int,int> mp;

    l(i,0,n){
        cin >> v[i];
        if(mp.find(v[i]-1) != mp.end()){
            mp[v[i]] = max( mp[v[i]], mp[v[i]-1]+1);
        }else{
            mp[v[i]] = 1;
        }
    }
    int len = 0;
    int val = 0;
    for(auto it : mp){
        if(it.y > len){
            len = it.y;
            val = it.x;
        }
    }
    cout << len << endl;
    int search = val-len+1;
    int i = 0;
    while( i < n && search <= val){
        if(v[i] == search){
            cout << i + 1 << " ";
            search++;
        }
        i++;
    }
    return 0;
}