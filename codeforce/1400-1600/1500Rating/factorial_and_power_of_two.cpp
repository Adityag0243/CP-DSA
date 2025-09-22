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



int popcount(int n)
{
	int ans = 0;
	while(n)
	{
		if(n&1)
		++ans;
		n>>=1;
		
	}
	return ans;
}


signed main(){
    fastio;

    
    vector<int> fact;
    int p = 2;
    l(i,3,20){
        p *= i;
        fact.pb(p);
    } 

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int num  = n;

        map<int,int> mp;
        
        for(int mask = 1; mask < (1<<15); mask++){
            int cur_num = 0;
            for(int i = 0; i<fact.size(); i++){
                if( (mask >> i) & 1) cur_num += fact[i]; 
            }
            mp[cur_num] =  popcount(mask);
        }

        int ans = popcount(n); 

        for(auto it : mp){
            if( n - it.x < 0) break;
            ans = min(ans, it.y + popcount(n - it.x));
            
        }   
        cout << ans << endl;

    }
    return 0;
}