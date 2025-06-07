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

map<int,int> fn(int x) {
    map<int,int> mp;
    for (int div = 2; div*div <= x; div++) {
        while (x % div == 0) {
            mp[div]++;
            x /= div;
        }
    }
    if (x > 1) mp[x]++;
    return mp;
}


// for specifically k = 3
//  for me any number pow(2,3j+2)* pow(13,1) * pow(19, 3*h1) === pow(2,2) * pow(13,3i+2)  * pow(19,3*h2)
// and both will be storead as reduced for of --> stored as pow(2,2)*pow(13,1)  
// and search for the no of compliment ---> pow(2,1) * pow(13,2)

pair<int,int> fn2( map<int,int> mp, int k){
    int red = 1;
    int comp = 1;

    for(auto it : mp){
        if( it.second % k == 0) continue;
        int times = it.second % k ;
        l(i,0,times) red *= it.first;
        l(i,0,k-times) comp *= it.first;
    }

    return {red, comp};
}

signed main(){
    int t = 1;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi v(n);

        int ans = 0;
        map<int,int> freq;
        l(i,0,n){
            cin >> v[i];
            auto mp = fn(v[i]);
            auto pr = fn2(mp, k);
            ans += freq[pr.second];
            freq[pr.first]++;
        }

         
        cout << ans;
    }
    return 0;
}