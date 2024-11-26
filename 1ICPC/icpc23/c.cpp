#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
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
        int n,k;
        cin >> n >>k;
        vi v(n);
        vector<bitset<2001>> bitsets(n);
        for(int i =0; i<k ; i++){
            int l,r,m;
            cin>>l>>r>>m;
            l--;
            r--;
            bitsets[l][m] = true;
            bitsets[r+1][m] = true;
            
            l(j,l,r+1){
                bitsets[j][m] = true;
            }
        }
        bool check = false;
        vi ans;
        l(i,0,n){
            bitsets[i][0] = true;
            bitsets[i].flip();
            int first_zero = bitsets[i]._Find_first();
            ans.push_back(first_zero);
            if(first_zero > n || first_zero < 1){
                check = true;
            }
            
        }
        
        if(check){
            cout<<-1<<endl;
        }else{
            l(i,0,ans.size()) cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}