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
        map<int,int> bits;
        l(i,0,n){
            int k;
            cin >> k;
            l(j,0,k){
                int bit;
                cin >> bit;
                // cout<<"bit: "<<bit<<"\n";
                if(bits.find(bit) == bits.end()) bits[bit] = -1*(i+1);
                else if(bits[bit] < 0 ) bits[bit] = 2;
                else bits[bit]++;

                // cout<<"bits[bit] "<<bits[bit]<<", ";
            }
            // l(j,0,6) cout<<bits[j]<<" ";
            // cout<<endl;
        }
        set<int> s;
        for(auto it:bits){
            if(it.second < 0){
                s.insert(it.second);
            }
        }

        // for (const auto& [key, value] : bits) {
        //     cout << "Key: " << key << ", Value: " << value << endl;
        // }
        // for(auto it:s) cout<<it<<" ";
        if(s.size() == n) no
        else yes

    }
}