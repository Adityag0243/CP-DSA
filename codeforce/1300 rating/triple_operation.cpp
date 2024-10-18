#include <bits/stdc++.h>
using namespace std;
#define ll(i , s , n)        for(int i = s; i < n; i++)
#define rl(i , s , n)        for(int i = s; i < n; i++)
#define all(arr)             arr.begin(), arr.end()
#define vi                   vector<int>
#define pi                   pair<int , int>
#define vvi                  vector<vi>
#define vpi                  vector<pi>
#define f                    first
#define s                    second
#define pb(x)                push_back(x)
#define ppb(x)               pop_back()
#define YES                  cout << "YES" << endl;
#define NO                   cout << "NO" << endl;
#define p(x)                 cout << (x) << endl;
#define sp(x)                cout << (x) << " ";
#define endl                 '\n'
#define lb(arr , x)          lower_bound(arr.begin() , arr.end() , x)
#define ub(arr , x)          upper_bound(arr.begin() , arr.end() , x)
#define bn(arr , x)          binary_search(arr.begin() , arr.end() , x)
#define mxv(arr)             *max_element(arr.begin(), arr.end())
#define mnv(arr)             *min_element(arr.begin(), arr.end())
#define smv(arr)             accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)             sort(arr.begin(), arr.end())
#define rsrt(arr)            sort(arr.begin(), arr.end() , greater<int>)
#define rev(arr)             reverse(all(arr))
#define MOD                  1000000007
#define l(i,st,n)       for(int i=st;i<n;i++)
#define lcm(a , b)           ((a) * (b)) / __gcd((a) , (b))
#define fastio               ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
vi power_3;
void solve() {
    int l , r; cin >> l >> r;
    int cnt = 0;

    int pos = lb(power_3 , l) - power_3.begin();
    

    int pos2 = lb(power_3 , r) - power_3.begin();

    if( pos == pos2){
        cnt = (r-l+1) * pos;
        p(cnt);
        return;
    }
    cnt += (power_3[pos] - l) * pos;
    cnt*=2;
    cout<<cnt<<" ";
    if(r != power_3[pos2]) pos2--;
    l(i,pos,pos2){
        cnt += (i+1)*(power_3[i+1] - power_3[i]);
    }
    cout<<cnt<<" ";
    pos = lb(power_3 , r) - power_3.begin();
    if( r == power_3[pos]){
        cnt++;
        cnt+= pos;
    }else
        cnt += ( r - power_3[pos-1] + 1) * pos;
    

    p(cnt);
}


signed main() {
    fastio;
    int num = 1;
    while(num < 200005){
        power_3.pb(num);
        num*=3;
    }
    int t; cin >> t;
    while (t--)
        solve();
}