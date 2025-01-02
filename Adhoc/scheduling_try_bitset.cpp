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

// wrong..thought and codeeee.................................


signed main(){
    
    
    int n;
    cin >> n;
    vector< bitset<1500> > v(n);  // as in one day there is 1440 minutes 
    l(i,0,n){                     // loop for(int i = 0;  i < n;  i++)
        int start_time , final_time;
        cin >> start_time >> final_time;

        l(j,start_time,final_time+1){
            v[i][j] = true;             // making all bitset true from Start time to final time
        }
    }
    int ans  = 0 ;
    l(i,0,n){
        int inner_cnt = 1; // atleast one event is selected

        l(j,0,n){
            if( (v[i] & v[j]) == 0 ){
                inner_cnt++;            // and is zero of two event means they do not oerlap 
            }
        }
        // now inner_cnt come up with the count of event can be//////////////////wrong
    }
        
    
}