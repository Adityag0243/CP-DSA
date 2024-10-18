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

int m, n;
vi v;
vi pre;

map< pair<int,int> , int> mp;
int cnt = 0;

int fn(int index, int icnt) {
    cnt++;
    int marks;

    if (index == n - 1) {
        if (v[index] == 0) return 0;
        else {
            if (v[index] < 0) return int(abs(v[index]) <= m - icnt);
            else return int(v[index] <= icnt);
        }
    }
    if(mp.find(make_pair(index,icnt)) != mp.end()) return mp[make_pair(index,icnt)];

    if (v[index] == 0) {
        marks = max(fn(index + 1, icnt + 1), fn(index + 1, icnt));
        mp[make_pair(index,icnt)] = marks;
        return marks;
    } else {

        int curr_ind = index;
        int addup = 0;
        while(curr_ind < n-1 && v[curr_ind] != 0){
            if(v[curr_ind] > 0 && icnt >= v[curr_ind]) addup++;
            else if(v[curr_ind] < 0 && pre[curr_ind]-icnt >= abs(v[curr_ind])) addup++;
            curr_ind++;
        }

        marks = fn(curr_ind , icnt);
        mp[make_pair(index,icnt)] = addup + marks;
        return addup + marks;
    } 
 
}

signed main() {
    cin >> n >> m;
    v.resize(n);
    pre.resize(n, 0);
    l(i, 0, n) cin >> v[i];
    if (v[0] == 0) pre[0] = 1;
    l(i, 1, n) {
        pre[i] += pre[i - 1];
        if (v[i] == 0) pre[i]++;
    }

    if (v[0] != 0) cout << fn(0, 0) << endl;
    else cout << fn(0, 0) << endl;
    cout<<"cnt: "<<cnt;
}
