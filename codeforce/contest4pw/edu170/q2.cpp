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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi d(n);

        l(i,0,n) cin >> d[i];
        l(i,0,n) d[i]= min(d[i]+i , n);

        vi st(n,0);
        int last = 0;
        int identity = 1;
        l(i,0,n){   
            last = max(last , i-1);
            if(s[i]=='R' && d[i] > last){
                st[last+1] += identity;
                last = min(d[i],n);
                st[last+1] -= identity;
                identity++;
            }
        }
        l(i,1,n) st[i]+=st[i-1];     
        int cnt = 0; 
        int prev= 0;
        bool check = true;
        l(i,0,n){
            if(s[i]=='B' && st[i]==0){
                check=false;
                break;
            }
            if(s[i]=='B' && st[i] != prev){
                prev = st[i];
                cnt+=1;
            }
        }
        if(check) cout<<cnt<<endl;
        else cout << -1 << endl;
        
        
    }
}